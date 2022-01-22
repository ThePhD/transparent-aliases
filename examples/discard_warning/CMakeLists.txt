add_executable(discard_warning source/discard_warning.c)
target_common_options(discard_warning)
add_test(NAME discard_warning COMMAND discard_warning)

add_executable(discard_warning.compile EXCLUDE_FROM_ALL source/discard_warning.c)
target_common_options(discard_warning.compile)
add_test(NAME discard_warning.compile
	COMMAND cmake --build . --target discard_warning
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
if (OFF)
	# right now, implementation isn't warning because of decl degredation in DeclRefExpr
	# which loses all the attributes.
	set_tests_properties(discard_warning.compile
		PROPERTIES
		WILL_FAIL true
		FAIl_REGULAR_EXPRESSION "*nodiscard*"
	)
endif()
