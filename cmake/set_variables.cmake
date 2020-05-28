function(set_variables)
    string(CONCAT bool_options "")
    string(CONCAT one_options "PREFIX;ENABLE_TESTING;BASE_SOURCE_DIR;"
        ";INCLUDE_DIR;SRC_DIR;TEST_SRC_DIR;EXTERNAL_DIR"
        ";USING_BUILD_UTILS;BUILD_UTILS_ENABLE_TESTING"
        ";BUILD_UTILS_DIR;BUILD_UTILS_VERSION;BUILD_UTILS_PREFIX")
    string(CONCAT list_options "COMPILE_OPTIONS")
    cmake_parse_arguments(set_variables "${bool_options}" "${one_options}" "${list_options}" ${ARGN}) 

    set(prefix ${set_variables_PREFIX})
    set(enable_testing ${set_variables_ENABLE_TESTING})
    set(base_source_dir ${set_variables_BASE_SOURCE_DIR})
    set(include_dir ${set_variables_INCLUDE_DIR})
    set(src_dir ${set_variables_SRC_DIR})
    set(test_src_dir ${set_variables_TEST_SRC_DIR})
    set(external_dir ${set_variables_EXTERNAL_DIR})
    set(using_build_utils ${set_variables_USING_BUILD_UTILS})
    set(build_utils_enable_testing ${set_variables_BUILD_UTILS_ENABLE_TESTING})
    set(build_utils_dir ${set_variables_BUILD_UTILS_DIR})
    set(build_utils_version ${set_variables_BUILD_UTILS_VERSION})
    set(build_utils_prefix ${set_variables_BUILD_UTILS_PREFIX})
    set(compile_options ${set_variables_COMPILE_OPTIONS})
    
    if (DEFINED TEST_PREFIX)
        set(TEST_PREFIX ${prefix} CACHE INTERNAL "Test prefix" FORCE)
    else()
        set(TEST_PREFIX "" CACHE INTERNAL "Test prefix" FORCE)
    endif()

    if (NOT DEFINED ${TEST_PREFIX}TEST_ENABLE_TESTING)
        set(${TEST_PREFIX}TEST_ENABLE_TESTING ${enable_testing} 
            CACHE BOOL "enable testing" FORCE)
    endif()

    unset(l_test_include_dir)
    if (NOT DEFINED ${TEST_PREFIX}TEST_INCLUDE_DIR
        OR ("${EMPTY}${${TEST_PREFIX}TEST_INCLUDE_DIR}" STREQUAL "${EMPTY}"))

        if (NOT "${EMPTY}${include_dir}" STREQUAL "${EMPTY}")
            get_filename_component(l_test_include_dir ${include_dir} ABSOLUTE)
        else()
            get_filename_component(l_test_include_dir ${base_source_dir}/../include ABSOLUTE)
        endif()
    else()
        get_filename_component(l_test_include_dir "${${TEST_PREFIX}TEST_INCLUDE_DIR}" ABSOLUTE)
    endif()

    if (DEFINED l_test_include_dir AND (IS_DIRECTORY ${l_test_include_dir}))
        set(${TEST_PREFIX}TEST_INCLUDE_DIR ${l_test_include_dir} 
            CACHE PATH "test include directory" FORCE)
    endif()

    unset(l_test_src_dir)
    if (NOT DEFINED ${TEST_PREFIX}TEST_SRC_DIR
        OR ("${EMPTY}${${TEST_PREFIX}TEST_SRC_DIR}" STREQUAL "${EMPTY}"))

        if (NOT "${EMPTY}${src_dir}" STREQUAL "${EMPTY}")
            get_filename_component(l_test_src_dir ${src_dir} ABSOLUTE)
        else()
            get_filename_component(l_test_src_dir ${base_source_dir}/../src ABSOLUTE)
        endif()
    else()
        get_filename_component(l_test_src_dir "${${TEST_PREFIX}TEST_SRC_DIR}" ABSOLUTE)
    endif()
    
    if (DEFINED l_test_src_dir AND (IS_DIRECTORY ${l_test_src_dir}))
        set(${TEST_PREFIX}TEST_SRC_DIR ${l_test_src_dir} 
            CACHE PATH "test source directory" FORCE)
    endif()

    unset(l_test_test_src_dir)
    if (NOT DEFINED ${TEST_PREFIX}TEST_TEST_SRC_DIR 
        OR ("${EMPTY}${${TEST_PREFIX}TEST_TEST_SRC_DIR}" STREQUAL "${EMPTY}"))
        
        if (NOT "${EMPTY}${test_src_dir}" STREQUAL "${EMPTY}")
            get_filename_component(l_test_test_src_dir ${test_src_dir} ABSOLUTE)
        else()
            get_filename_component(l_test_test_src_dir ${base_source_dir}/../test ABSOLUTE)
        endif()
    else()
        get_filename_component(l_test_test_src_dir "${${TEST_PREFIX}TEST_TEST_SRC_DIR}" ABSOLUTE)
    endif()
    
    if (DEFINED l_test_test_src_dir AND(IS_DIRECTORY ${l_test_test_src_dir}))
        set(${TEST_PREFIX}TEST_TEST_SRC_DIR ${l_test_test_src_dir} 
            CACHE PATH "test test source directory" FORCE)
    endif()

    unset(l_test_external_dir)
    if (NOT DEFINED ${TEST_PREFIX}TEST_EXTERNAL_DIR
        OR ("${EMPTY}${${TEST_PREFIX}TEST_EXTERNAL_DIR}" STREQUAL "${EMPTY}"))

        if (NOT "${EMPTY}${external_dir}" STREQUAL "${EMPTY}")
            get_filename_component(l_test_external_dir ${external_dir} ABSOLUTE)
        else()
            get_filename_component(l_test_external_dir ${base_source_dir}/../external ABSOLUTE)
        endif()
    else()
        get_filename_component(l_test_external_dir "${${TEST_PREFIX}TEST_EXTERNAL_DIR}" ABSOLUTE)
    endif()

    if (DEFINED l_test_external_dir AND (IS_DIRECTORY ${l_test_external_dir}))
        set(${TEST_PREFIX}TEST_EXTERNAL_DIR ${l_test_external_dir} 
            CACHE PATH "test external directory" FORCE)
    endif()

    if (NOT DEFINED ${TEST_PREFIX}TEST_USING_BUILD_UTILS)
        set(l_using_build_utils TRUE)
        if (NOT "${EMPTY}${using_build_utils}" STREQUAL "${EMPTY}")
            set(l_using_build_utils ${using_build_utils})
        endif()
        set(${TEST_PREFIX}TEST_USING_BUILD_UTILS
            ${using_build_utils} CACHE BOOL "using build utils" FORCE)
    endif()

    if (${TEST_PREFIX}TEST_USING_BUILD_UTILS)

        if (NOT DEFINED ${TEST_PREFIX}TEST_BUILD_UTILS_ENABLE_TESTING)
            set(${TEST_PREFIX}TEST_BUILD_UTILS_ENABLE_TESTING ${build_utils_enable_testing}
                CACHE BOOL "build utils enable testing" FORCE)
        endif()

        unset(l_test_build_utils_dir)
        if (NOT DEFINED ${TEST_PREFIX}TEST_BUILD_UTILS_DIR
            OR ("${EMPTY}${${TEST_PREFIX}TEST_BUILD_UTILS_DIR}" STREQUAL "${EMPTY}"))

            if (NOT "${EMPTY}${build_utils_dir}" STREQUAL "${EMPTY}")
                get_filename_component(l_test_build_utils_dir ${build_utils_dir} ABSOLUTE)
            else()
                get_filename_component(l_test_build_utils_dir 
                    "${${TEST_PREFIX}TEST_EXTERNAL_DIR}/build_utils" ABSOLUTE)
            endif()
        else()
            get_filename_component(l_test_build_utils_dir 
                "${${TEST_PREFIX}TEST_BUILD_UTILS_DIR}" ABSOLUTE)
        endif()

        if (DEFINED l_test_build_utils_dir AND (IS_DIRECTORY ${l_test_build_utils_dir}))
            set(${TEST_PREFIX}TEST_BUILD_UTILS_DIR ${l_test_build_utils_dir} 
                CACHE PATH "test build_utils directory" FORCE)
        endif()

        if (NOT DEFINED ${TEST_PREFIX}TEST_BUILD_UTILS_VERSION)
            if (NOT "${EMPTY}${build_utils_version}" STREQUAL "${EMPTY}")
                set(${TEST_PREFIX}TEST_BUILD_UTILS_VERSION ${build_utils_version} 
                    CACHE STRING "build utils version" FORCE)
            else()
                if (EXISTS ${base_source_dir}/build_utils_VERSION.cmake)
                    include(${base_source_dir}/build_utils_VERSION.cmake)
                    set(${TEST_PREFIX}TEST_BUILD_UTILS_VERSION ${build_utils_VERSION} 
                        CACHE STRING "build utils version" FORCE)
                    unset(build_utils_VERSION CACHE)
                endif()
            endif()
        endif()

        if (NOT DEFINED ${TEST_PREFIX}TEST_BUILD_UTILS_PREFIX)
            set(${TEST_PREFIX}TEST_BUILD_UTILS_PREFIX ${build_utils_prefix} 
                CACHE STRING "build_utils prefix" FORCE)
        endif()
    endif()
    
    if (NOT DEFINED ${TEST_PREFIX}TEST_COMPILE_OPTIONS)
        set(${TEST_PREFIX}TEST_COMPILE_OPTIONS ${compile_options} 
            CACHE STRING "Compile options" FORCE)
    endif()

endfunction(set_variables)
