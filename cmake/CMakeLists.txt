cmake_minimum_required (VERSION 3.0.2)

project(test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/test CACHE PATH "..." FORCE)
endif()

if (NOT DEFINED EMPTY)
    set(EMPTY "_empty_" CACHE INTERNAL "Empty" FORCE)
endif()

unset(l_base_cmake_src_dir)
if (NOT DEFINED TEST_CMAKE_BASE_SRC_DIR
    OR("${EMPTY}${TEST_CMAKE_BASE_SRC_DIR}" STREQUAL "${EMPTY}"))

    get_filename_component(l_base_cmake_src_dir "${CMAKE_SOURCE_DIR}" ABSOLUTE)
else()
    get_filename_component(l_base_cmake_src_dir "${l_base_cmake_src_dir}" ABSOLUTE)
endif()

set(TEST_CMAKE_BASE_SRC_DIR ${l_base_cmake_src_dir} 
    CACHE INTERNAL "test cmake source directory" FORCE)

unset(l_test_prefix)
if (DEFINED TEST_PREFIX AND (NOT "${EMPTY}${TEST_PREFIX}" STREQUAL "${EMPTY}"))
    set(l_test_prefix "${TEST_PREFIX}_")
endif()

if (NOT DEFINED TEST_USING_BUILD_UTILS)
    set(TEST_USING_BUILD_UTILS TRUE 
        CACHE BOOL "test using build-utils" FORCE)
endif()

include(${TEST_CMAKE_BASE_SRC_DIR}/set_variables.cmake)

set_variables(PREFIX ${l_test_prefix}
    USING_BUILD_UTILS ${TEST_USING_BUILD_UTILS}
    BUILD_UTILS_ENABLE_TESTING ${TEST_BUILD_UTILS_ENABLE_TESTING}
    ENABLE_TESTING ${TEST_ENABLE_TESTING}
    TEST_SRC_DIR ${TEST_TEST_SRC_DIR}
    INCLUDE_DIR ${TEST_INCLUDE_DIR}
    EXTERNAL_DIR ${TEST_EXTERNAL_DIR}
    BUILD_UTILS_DIR ${TEST_BUILD_UTILS_DIR}
    BUILD_UTILS_VERSION ${TEST_BUILD_UTILS_VERSION}
    BUILD_UTILS_PREFIX ${TEST_BUILD_UTILS_PREFIX}
    COMPILE_OPTIONS ${TEST_COMPILE_OPTIONS})

find_package(Git)

if (NOT GIT_FOUND)
    message(FATAL_ERROR "Git not found")
endif()

if (${TEST_PREFIX}TEST_USING_BUILD_UTILS)
    execute_process(COMMAND "${GIT_EXECUTABLE}" "fetch" "--tags" 
        WORKING_DIRECTORY ${${TEST_PREFIX}TEST_BUILD_UTILS_DIR})
    execute_process(COMMAND "${GIT_EXECUTABLE}" "checkout" "${${TEST_PREFIX}TEST_BUILD_UTILS_VERSION}" 
        WORKING_DIRECTORY ${${TEST_PREFIX}TEST_BUILD_UTILS_DIR})
    set(BUILD_UTILS_CMAKE_BASE_SRC_DIR ${${TEST_PREFIX}TEST_BUILD_UTILS_DIR}/cmake 
        CACHE INTERNAL "..." FORCE)
    set(BUILD_UTILS_PREFIX ${TEST_PREFIX}TEST
        CACHE INTERNAL "..." FORCE)
    add_subdirectory(${${TEST_PREFIX}TEST_BUILD_UTILS_DIR}/cmake build_utils)

    include_build_util(NAME add_test_executable_dir 
        INCLUDE_DIR ${${BUILD_UTILS_PREFIX}BUILD_UTILS_INCLUDE_DIR})

    add_test_executable_dir(${${TEST_PREFIX}TEST_TEST_SRC_DIR}
        RECURSIVE PREFIX "Test" SRC_EXT "cpp" SRC_TAG "main"
        GET_TARGET_NAME ${TEST_CMAKE_BASE_SRC_DIR}/build_utils/add_test_executable_dir/get_target_name.cmake
        GET_TARGET_DIR ${TEST_CMAKE_BASE_SRC_DIR}/build_utils/add_test_executable_dir/get_target_dir.cmake
        INCLUDE_DIR ${${BUILD_UTILS_PREFIX}BUILD_UTILS_INCLUDE_DIR})

    unset(BUILD_UTILS_BASE_SOURCE_DIR CACHE)
else()
    message(FATAL_ERROR "Build Not Defined")
endif()

enable_testing()

install (DIRECTORY ${PROJECT_SOURCE_DIR}/../include/ DESTINATION test/include)

set(INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/test)
