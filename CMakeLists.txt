cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(my-league)

# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if (MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else ()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic -Werror)
endif ()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# FetchContent_MakeAvailable was not added until CMake 3.14
if (${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif ()

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.11.1
)

#Add json library
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent.git
        GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# Adds Catch2 testing library
FetchContent_GetProperties(catch2)
if (NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif ()

get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE)
get_filename_component(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)


include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

list(APPEND CORE_SOURCE_FILES src/core/riot_parser.cc
        src/core/api_handler.cc
        src/core/input_handler.cc
        src/core/summoner_info.cc
        src/core/ranked_league.cc
        src/core/ranked_league_container.cc
        src/core/champion.cc
        src/core/champion_filterer.cc
        src/core/statistics_analyzer.cc)

list(APPEND INTERFACE_SOURCE_FILES src/interface/my_league_app.cc
        src/interface/screen.cc
        src/interface/main_screen.cc)

list(APPEND TEST_FILES tests/test_main.cc
        tests/test_api_handler.cc)

add_executable(my-league apps/my_league_main.cc ${CORE_SOURCE_FILES})
target_include_directories(my-league PRIVATE include)

# Obtain libcurl for HTTP requests
set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(my-league ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)

ci_make_app(
        APP_NAME my-league-app
        CINDER_PATH ${CINDER_PATH}
        SOURCES apps/my_league_app_main.cc ${INTERFACE_SOURCE_FILES} ${CORE_SOURCE_FILES}
        INCLUDES include
)

ci_make_app(
        APP_NAME my-league-test
        CINDER_PATH ${CINDER_PATH}
        SOURCES tests/test_main.cc ${CORE_SOURCE_FILES} ${TEST_FILES}
        INCLUDES include
        LIBRARIES catch2
)

target_link_libraries(my-league-app ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)
target_link_libraries(my-league-test ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)

if (MSVC)
    set_property(TARGET my-league-test APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
endif ()