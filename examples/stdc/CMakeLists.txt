add_executable(example1 source/example1.c)
target_common_options(example1)
add_test(NAME example1 COMMAND example1)

add_executable(example2 source/example2.c)
target_common_options(example2)
add_test(NAME example2 COMMAND example2)

# this one has on-purpose errors
add_executable(example3 EXCLUDE_FROM_ALL source/example3.c)
target_common_options(example3)
set_target_properties(example3
	PROPERTIES
	EXCLUDE_FROM_ALL TRUE
	EXCLUDE_FROM_DEFAULT_BUILD TRUE
)
add_test(NAME example3
	COMMAND cmake --build . --target example3
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
set_tests_properties(example3
	PROPERTIES
	WILL_FAIL true
	FAIL_REGULAR_EXPRESSION "error: use of undeclared identifier 'sleep_alias';error: 'zzz' cannot be redeclared as a transparent alias because it already exists as a function declaration;'truncated_zzz' cannot be redeclared as a transparent alias because it already exists as a function declaration;error: 'valid_sleep_alias' cannot be redeclared as it is already a transparent alias;error: 'x' is not a valid transparent alias target;5 errors generated."
)

add_executable(example4 source/example4.c)
target_common_options(example4)
add_test(NAME example4 COMMAND example4)
