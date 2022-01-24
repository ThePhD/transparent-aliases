add_executable(discard_warning source/discard_warning.c)
target_common_options(discard_warning)
target_compile_options(discard_warning
	PRIVATE
	-Wno-unused-result
)
add_test(NAME discard_warning COMMAND discard_warning)

add_executable(discard_warning.compile EXCLUDE_FROM_ALL source/discard_warning.c)
target_common_options(discard_warning.compile)
# force the discard_warning.compile target
# to rebuild every time, by deleting its object and executable files!
add_test(NAME discard_warning.compile.clean
	COMMAND cmake -E rm -f $<TARGET_FILE:discard_warning.compile> $<TARGET_OBJECTS:discard_warning.compile>
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
add_test(NAME discard_warning.compile
	COMMAND cmake --build . --target discard_warning.compile
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
set_tests_properties(discard_warning.compile
	PROPERTIES
	DEPENDS discard_warning.compile.clean
	PASS_REGULAR_EXPRESSION "5.*nodiscard;6.*nodiscard"
)
