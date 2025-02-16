
cmake_minimum_required(VERSION 3.5)

project(print_ip )

add_executable(print_ip main.cpp )

set (ALL_SOURCES print_ip)

set_target_properties(${ALL_SOURCES} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

foreach(s ${ALL_SOURCES})
	if (MSVC)
		target_compile_options(${s} PRIVATE
			/W4
		)
		
	else ()
		target_compile_options(${s} PRIVATE
			-Wall 
		)
	endif()
endforeach()

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

