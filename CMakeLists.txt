cmake_minimum_required(VERSION 3.21)

project(transparent-aliases
	VERSION 1.0.0
	LANGUAGES C CXX)

function(target_common_options target)
	target_compile_options(${target}
		PRIVATE
		-std=c2x
		-fforce-enable-int128
		-Wall
		-Wpedantic
	)
	target_include_directories(${target}
		PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/include
	)
endfunction()

option(TRANSPARENT_ALIASES_TESTS ON "All built code will also be tested.")

if (TRANSPARENT_ALIASES_TESTS)
	enable_testing()
endif()

add_subdirectory(examples)
