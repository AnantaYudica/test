cmake_minimum_required (VERSION 3.0.2)

project(test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/test CACHE PATH "..." FORCE)
endif()

if (NOT DEFINED EXTERNAL_DIR)
    set(EXTERNAL_DIR ${PROJECT_SOURCE_DIR}/../external 
        CACHE PATH "External Directory" FORCE)
endif()

if (NOT DEFINED TEST_BASE_SOURCE_DIR)
    get_filename_component(l_base_source_dir "${TEST_BASE_SOURCE_DIR}" ABSOLUTE)
else()
     get_filename_component(l_base_source_dir "${CMAKE_SOURCE_DIR}" ABSOLUTE)
endif()

set(TEST_BASE_SOURCE_DIR ${l_base_source_dir}
    CACHE PATH "Test Base Source Directory" FORCE)

if (NOT DEFINED TEST_SRC_DIR)
    set(TEST_SRC_DIR ${PROJECT_SOURCE_DIR}/../test 
        CACHE PATH "Test Source Directory" FORCE)
endif()

get_filename_component(TEST_SRC_DIR "${TEST_SRC_DIR}" ABSOLUTE)

if (NOT DEFINED USING_BUILD_UTILS)
    set(USING_BUILD_UTILS TRUE
        CACHE BOOL "using build_utils" FORCE)
endif()

if (NOT DEFINED BUILD_UTILS_DIR)
    set(BUILD_UTILS_DIR ${EXTERNAL_DIR}/build_utils
        CACHE PATH "build_utils Directory" FORCE)
endif()

if (NOT DEFINED BUILD_UTILS_VERSION)
    set(BUILD_UTILS_VERSION "v0.1.1-cmake" 
        CACHE STRING "build_utils version" FORCE)
endif()

if (NOT DEFINED ENABLE_TESTING)
    set(ENABLE_TESTING TRUE
        CACHE BOOL "enable testing" FORCE)
endif()

find_package(Git)

if (NOT GIT_FOUND)
    message(FATAL_ERROR "Git not found")
endif()

if (USING_BUILD_UTILS)
    execute_process(COMMAND "${GIT_EXECUTABLE}" "fetch" "--tags" 
        WORKING_DIRECTORY ${BUILD_UTILS_DIR})
    execute_process(COMMAND "${GIT_EXECUTABLE}" "checkout" "${BUILD_UTILS_VERSION}" 
        WORKING_DIRECTORY ${BUILD_UTILS_DIR})
    set(BUILD_UTILS_BASE_SOURCE_DIR ${BUILD_UTILS_DIR}/cmake CACHE PATH "..." FORCE)
    add_subdirectory(${BUILD_UTILS_DIR}/cmake build_utils)

    include_build_util(NAME add_test_executable_dir)

    add_test_executable_dir(${TEST_SRC_DIR}
        RECURSIVE PREFIX "Test" SRC_EXT "cpp" SRC_TAG "main"
        GET_TARGET_NAME ${TEST_BASE_SOURCE_DIR}/build_utils/add_test_executable_dir/get_target_name.cmake
        GET_TARGET_DIR ${TEST_BASE_SOURCE_DIR}/build_utils/add_test_executable_dir/get_target_dir.cmake)

    unset(BUILD_UTILS_BASE_SOURCE_DIR)
else()
    message(FATAL_ERROR "Build Not Defined")
endif()

enable_testing()

install (DIRECTORY ${PROJECT_SOURCE_DIR}/../include/ DESTINATION test/include)

set(INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/test)
