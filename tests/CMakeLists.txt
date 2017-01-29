link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add test executable
function( add_test_executable name )
        set( sourceFiles
                ${name}.cc )

    add_executable( test_${name}.o ${sourceFiles} )
    add_test(${name} test_${name}.o)

    # Link with asagi
    target_link_libraries( test_${name}.o impalajit)
endfunction( add_test_executable )


include_directories(include)


add_test_executable(conditionals_eq)
add_test_executable(conditionals_lt)
add_test_executable(conditionals_gt)
add_test_executable(conditionals_neq)
add_test_executable(conditionals_lte)
add_test_executable(conditionals_gte)
add_test_executable(conditionals_nested)
add_test_executable(conditionals_complex_1)
add_test_executable(conditionals_complex_2)
add_test_executable(multiple_functions)