function(add_test_executable_dir_get_target_name out_target_name)
    
    string(CONCAT one_options "PREFIX;PREFIX_DIR"
        ";BASE_DIR;PATH;RELATIVE_PATH;FILENAME;NAME;TAG;EXT"
        ";CURR_DIR;RELATIVE_CURR_DIR;CURR_DIRNAME;INCLUDE_DIR")
    cmake_parse_arguments(add_test_executable_dir_get_target_name "" 
        "${one_options}" "ARGS" ${ARGN}) 

    set(prefix ${add_test_executable_dir_get_target_name_PREFIX})
    set(include_dir ${add_test_executable_dir_get_target_name_INCLUDE_DIR})

    include_build_util(NAME upper_str 
        INCLUDE_DIR ${include_dir})

    set(name ${add_test_executable_dir_get_target_name_NAME})
    
    upper_str("${name}" name INDEX 0 LENGTH 1)

    set(${out_target_name} "${prefix}${name}" PARENT_SCOPE)

endfunction(add_test_executable_dir_get_target_name)
