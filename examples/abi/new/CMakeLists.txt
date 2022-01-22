add_library(my_libc.new SHARED ../my_libc/source/maxabs.c)
target_common_options(my_libc.new)
target_compile_definitions(my_libc.new
	PRIVATE
	MY_LIBC_BUILDING=1

	PUBLIC
	NEW_CODE=1
	OLD_CODE=0
)
target_include_directories(my_libc.new
	PUBLIC
	../my_libc/include
)
set_target_properties(my_libc.new
	PROPERTIES
	OUTPUT_NAME "my_libc"
)

add_executable(app_new.lib_new ../app/source/app.c)
target_common_options(app_new.lib_new)
target_link_libraries(app_new.lib_new
	PRIVATE
	my_libc.new
)

# we indicate success by saying it was "skipped"
# weird, I know, but it's just how we have to do until
# we get a better CMake command, lmao
add_test(NAME app_new.lib_new COMMAND app_new.lib_new)

# we need to effectively transplant the old executable here and pretend like everything is peachy-okay!
add_test(NAME app_old.lib_new-copy
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:app_old.lib_old> ${CMAKE_CURRENT_BINARY_DIR}
)
add_test(NAME app_old.lib_new COMMAND "${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_FILE_NAME:app_old.lib_old>"
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
set_tests_properties(app_old.lib_new
	PROPERTIES
	DEPENDS app_old.lib_new-copy
)
