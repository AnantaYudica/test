function(add_test_executable_dir_get_target_dir out_dir_name)
    
    string(CONCAT one_options "BASE_DIR;PATH;RELATIVE_PATH;DIRNAME;NAME;TAG"
        ";CURR_DIR;RELATIVE_CURR_DIR;CURR_DIRNAME;INCLUDE_DIR")
    cmake_parse_arguments(add_test_executable_dir_get_target_dir "" 
        "${one_options}" "ARGS" ${ARGN}) 

    set(dirname "${add_test_executable_dir_get_target_dir_DIRNAME}")
    set(include_dir ${add_test_executable_dir_get_target_dir_INCLUDE_DIR})

    include_build_util(NAME upper_str 
        INCLUDE_DIR ${include_dir})
        
    upper_str("${dirname}" dirname INDEX 0 LENGTH 1)

    set(${out_dir_name} "${dirname}" PARENT_SCOPE)

endfunction(add_test_executable_dir_get_target_dir)
