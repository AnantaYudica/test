function(set_variables)
    string(CONCAT bool_options "")
    string(CONCAT one_options "PREFIX;ENABLE_TESTING;"
        ";INCLUDE_DIR;SRC_DIR;TEST_SRC_DIR;EXTERNAL_DIR"
        ";USING_BUILD_UTILS;BUILD_UTILS_ENABLE_TESTING"
        ";BUILD_UTILS_DIR;BUILD_UTILS_VERSION;BUILD_UTILS_PREFIX")
    string(CONCAT list_options "COMPILE_OPTIONS")
    cmake_parse_arguments(set_variables "${bool_options}" "${one_options}" "${list_options}" ${ARGN}) 

    set(prefix ${set_variables_PREFIX})
    set(enable_testing ${set_variables_ENABLE_TESTING})
    set(include_dir ${set_variables_INCLUDE_DIR})
    set(src_dir ${set_variables_SRC_DIR})
    set(test_src_dir ${set_variables_TEST_SRC_DIR})
    set(external_dir ${set_variables_EXTERNAL_DIR})
    set(using_build_utils ${set_variables_USING_BUILD_UTILS})
    set(build_utils_enable_testing ${set_variables_BUILD_UTILS_ENABLE_TESTING})
    set(build_utils_dir ${set_variables_BUILD_UTILS_DIR})
    set(build_utils_version ${set_variables_BUILD_UTILS_VERSION})
    set(compile_options ${set_variables_COMPILE_OPTIONS})
    
    unset(l_prefix)
    if (NOT "${EMPTY}${prefix}" STREQUAL "${EMPTY}")
        set(l_prefix ${prefix})
    elseif (DEFINED TEST_PREFIX)
        set(l_prefix ${TEST_PREFIX})
    else()
        set(l_prefix "")
    endif()

    if (NOT "${EMPTY}${l_prefix}" STREQUAL "${EMPTY}")
        string(TOUPPER "${l_prefix}" l_prefix_upper)
        set(TEST_PREFIX ${prefix} CACHE INTERNAL "Test prefix string" FORCE)
        set(TEST_PREFIX_UPPER_ "${l_prefix_upper}_" CACHE INTERNAL "Test prefix string" FORCE)
        unset(l_prefix_upper)
    else()
        set(TEST_PREFIX "" CACHE INTERNAL "Test prefix string" FORCE)
        set(TEST_PREFIX_UPPER_ "" CACHE INTERNAL "Test prefix string" FORCE)
    endif()

    unset(l_base_cmake_src_dir)
    if (NOT DEFINED TEST_CMAKE_BASE_SRC_DIR
        OR("${EMPTY}${TEST_CMAKE_BASE_SRC_DIR}" STREQUAL "${EMPTY}"))

        get_filename_component(l_base_cmake_src_dir "${CMAKE_SOURCE_DIR}" ABSOLUTE)
        set(TEST_CMAKE_BASE_SRC_DIR ${l_base_cmake_src_dir} 
            CACHE INTERNAL "test cmake source directory" FORCE)
    endif()

    if (NOT IS_DIRECTORY ${TEST_CMAKE_BASE_SRC_DIR})
        message(FATAL_ERROR "\"TEST_CMAKE_BASE_SRC_DIR\" is not directory")
    endif()

    get_property(test_enable_testing_cache_type 
        CACHE ${TEST_PREFIX_UPPER_}TEST_ENABLE_TESTING
        PROPERTY TYPE)
    if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_ENABLE_TESTING
        OR(NOT "${EMPTY}${test_enable_testing_cache_type}" STREQUAL "${EMPTY}BOOL"))

        set(${TEST_PREFIX_UPPER_}TEST_ENABLE_TESTING ${enable_testing} 
            CACHE BOOL "enable testing" FORCE)
    endif()
    unset(test_enable_testing_cache_type)

    unset(l_test_include_dir)
    if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_INCLUDE_DIR
        OR ("${EMPTY}${${TEST_PREFIX_UPPER_}TEST_INCLUDE_DIR}" STREQUAL "${EMPTY}"))

        if (NOT "${EMPTY}${include_dir}" STREQUAL "${EMPTY}")
            get_filename_component(l_test_include_dir ${include_dir} ABSOLUTE)
        else()
            get_filename_component(l_test_include_dir ${TEST_CMAKE_BASE_SRC_DIR}/../include ABSOLUTE)
        endif()
    else()
        get_filename_component(l_test_include_dir "${${TEST_PREFIX_UPPER_}TEST_INCLUDE_DIR}" ABSOLUTE)
    endif()

    if (IS_DIRECTORY ${l_test_include_dir})
        set(${TEST_PREFIX_UPPER_}TEST_INCLUDE_DIR ${l_test_include_dir} 
            CACHE PATH "test include directory" FORCE)
    else()
        message(FATAL_ERROR "\"INCLUDE_DIR\" is not directory")
    endif()

    unset(l_test_src_dir)
    if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_SRC_DIR
        OR ("${EMPTY}${${TEST_PREFIX_UPPER_}TEST_SRC_DIR}" STREQUAL "${EMPTY}"))

        if (NOT "${EMPTY}${src_dir}" STREQUAL "${EMPTY}")
            get_filename_component(l_test_src_dir ${src_dir} ABSOLUTE)
        else()
            get_filename_component(l_test_src_dir ${TEST_CMAKE_BASE_SRC_DIR}/../src ABSOLUTE)
        endif()
    else()
        get_filename_component(l_test_src_dir "${${TEST_PREFIX_UPPER_}TEST_SRC_DIR}" ABSOLUTE)
    endif()
    
    if (IS_DIRECTORY ${l_test_src_dir})
        set(${TEST_PREFIX_UPPER_}TEST_SRC_DIR ${l_test_src_dir} 
            CACHE PATH "test source directory" FORCE)
    else()
        
    endif()

    unset(l_test_test_src_dir)
    if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_TEST_SRC_DIR 
        OR ("${EMPTY}${${TEST_PREFIX_UPPER_}TEST_TEST_SRC_DIR}" STREQUAL "${EMPTY}"))
        
        if (NOT "${EMPTY}${test_src_dir}" STREQUAL "${EMPTY}")
            get_filename_component(l_test_test_src_dir ${test_src_dir} ABSOLUTE)
        else()
            get_filename_component(l_test_test_src_dir ${TEST_CMAKE_BASE_SRC_DIR}/../test ABSOLUTE)
        endif()
    else()
        get_filename_component(l_test_test_src_dir "${${TEST_PREFIX_UPPER_}TEST_TEST_SRC_DIR}" ABSOLUTE)
    endif()
    
    if (IS_DIRECTORY ${l_test_test_src_dir})
        set(${TEST_PREFIX_UPPER_}TEST_TEST_SRC_DIR ${l_test_test_src_dir} 
            CACHE PATH "test test source directory" FORCE)
    else()
        message(FATAL_ERROR "\"TEST_SRC_DIR\" is not directory")
    endif()

    unset(l_test_external_dir)
    if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_EXTERNAL_DIR
        OR ("${EMPTY}${${TEST_PREFIX_UPPER_}TEST_EXTERNAL_DIR}" STREQUAL "${EMPTY}"))

        if (NOT "${EMPTY}${external_dir}" STREQUAL "${EMPTY}")
            get_filename_component(l_test_external_dir ${external_dir} ABSOLUTE)
        else()
            get_filename_component(l_test_external_dir ${TEST_CMAKE_BASE_SRC_DIR}/../external ABSOLUTE)
        endif()
    else()
        get_filename_component(l_test_external_dir "${${TEST_PREFIX_UPPER_}TEST_EXTERNAL_DIR}" ABSOLUTE)
    endif()

    if (IS_DIRECTORY ${l_test_external_dir})
        set(${TEST_PREFIX_UPPER_}TEST_EXTERNAL_DIR ${l_test_external_dir} 
            CACHE PATH "test external directory" FORCE)
    else()
        message(FATAL_ERROR "\"EXTERNAL_DIR\" is not directory")
    endif()

    if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_USING_BUILD_UTILS)
        set(l_using_build_utils TRUE)
        if (NOT "${EMPTY}${using_build_utils}" STREQUAL "${EMPTY}")
            set(l_using_build_utils ${using_build_utils})
        endif()
        set(${TEST_PREFIX_UPPER_}TEST_USING_BUILD_UTILS
            ${using_build_utils} CACHE BOOL "using build utils" FORCE)
    endif()

    if (${TEST_PREFIX_UPPER_}TEST_USING_BUILD_UTILS)

        if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_BUILD_UTILS_ENABLE_TESTING)
            set(${TEST_PREFIX_UPPER_}TEST_BUILD_UTILS_ENABLE_TESTING ${build_utils_enable_testing}
                CACHE BOOL "build utils enable testing" FORCE)
        endif()

        unset(l_test_build_utils_dir)
        if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_BUILD_UTILS_DIR
            OR ("${EMPTY}${${TEST_PREFIX_UPPER_}TEST_BUILD_UTILS_DIR}" STREQUAL "${EMPTY}"))

            if (NOT "${EMPTY}${build_utils_dir}" STREQUAL "${EMPTY}")
                get_filename_component(l_test_build_utils_dir ${build_utils_dir} ABSOLUTE)
            else()
                get_filename_component(l_test_build_utils_dir 
                    "${${TEST_PREFIX_UPPER_}TEST_EXTERNAL_DIR}/build_utils" ABSOLUTE)
            endif()
        else()
            get_filename_component(l_test_build_utils_dir 
                "${${TEST_PREFIX_UPPER_}TEST_BUILD_UTILS_DIR}" ABSOLUTE)
        endif()

        if (IS_DIRECTORY ${l_test_build_utils_dir})
            set(${TEST_PREFIX_UPPER_}TEST_BUILD_UTILS_DIR ${l_test_build_utils_dir} 
                CACHE PATH "test build_utils directory" FORCE)
        else()
            message(FATAL_ERROR "\"BUILD_UTILS_DIR\" is not directory")
        endif()

        if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_BUILD_UTILS_VERSION)
            if (NOT "${EMPTY}${build_utils_version}" STREQUAL "${EMPTY}")
                set(${TEST_PREFIX_UPPER_}TEST_BUILD_UTILS_VERSION ${build_utils_version} 
                    CACHE STRING "build utils version" FORCE)
            else()
                if (EXISTS ${TEST_CMAKE_BASE_SRC_DIR}/build_utils_VERSION.cmake)
                    include(${TEST_CMAKE_BASE_SRC_DIR}/build_utils_VERSION.cmake)
                    set(${TEST_PREFIX_UPPER_}TEST_BUILD_UTILS_VERSION ${build_utils_VERSION} 
                        CACHE STRING "build utils version" FORCE)
                    unset(build_utils_VERSION CACHE)
                endif()
            endif()
        endif()

    endif()

    get_property(test_compile_option_cache_type 
        CACHE ${TEST_PREFIX_UPPER_}TEST_COMPILE_OPTIONS
        PROPERTY TYPE)
    if (NOT DEFINED ${TEST_PREFIX_UPPER_}TEST_COMPILE_OPTIONS
        OR("${EMPTY}${test_compile_option_cache_type}" STREQUAL "${EMPTY}")
        OR("${EMPTY}${test_compile_option_cache_type}" STREQUAL "${EMPTY}INTERNAL"))

        set(${TEST_PREFIX_UPPER_}TEST_COMPILE_OPTIONS ${compile_options} 
            CACHE STRING "Compile options" FORCE)
    endif()

    unset(list_compile_option_arg)
    set(compile_options_elem_keyword "")
    foreach(compile_options_elem ${${TEST_PREFIX_UPPER_}TEST_COMPILE_OPTIONS})
        if ("${EMPTY}${compile_options_elem}" STREQUAL "${EMPTY}INTERFACE"
            OR("${EMPTY}${compile_options_elem}" STREQUAL "${EMPTY}PUBLIC")
            OR("${EMPTY}${compile_options_elem}" STREQUAL "${EMPTY}PRIVATE"))
                set(compile_options_elem_keyword ${compile_options_elem})
        else()
            if ("${EMPTY}${compile_options_elem_keyword}" STREQUAL "${EMPTY}")
                list(APPEND list_compile_option_arg "PUBLIC" ${compile_options_elem})
            else()
                list(APPEND list_compile_option_arg ${compile_options_elem_keyword} ${compile_options_elem})
            endif()
        endif()
    endforeach(compile_options_elem)
    set(${TEST_PREFIX_UPPER_}LIST_COMPILE_OPTION_ARG ${list_compile_option_arg}
        CACHE INTERNAL "" FORCE)
    unset(compile_options_elem_keyword)
    unset(list_compile_option_arg)

endfunction(set_variables)
