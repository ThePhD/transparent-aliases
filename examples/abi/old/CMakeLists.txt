add_library(my_libc.old SHARED
	../my_libc/source/maxabs.c
)
target_common_options(my_libc.old)
target_compile_definitions(my_libc.old
	PRIVATE
	MY_LIBC_BUILDING=1

	PUBLIC
	NEW_CODE=0
	OLD_CODE=1
)
target_include_directories(my_libc.old
	PUBLIC
	../my_libc/include
)
set_target_properties(my_libc.old
	PROPERTIES
	OUTPUT_NAME "my_libc"
)

add_executable(app_old.lib_old ../app/source/app.c)
target_common_options(app_old.lib_old)
target_link_libraries(app_old.lib_old
	PRIVATE
	my_libc.old
)
set_target_properties(app_old.lib_old
	PROPERTIES
	SKIP_BUILD_RPATH FALSE
	BUILD_RPATH [=[${ORIGIN}]=]
	INSTALL_RPATH "${CMAKE_INSTALL_LIBDIR}"
)

add_test(NAME app_old.lib_old COMMAND app_old.lib_old)
