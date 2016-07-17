cmake_minimum_required(VERSION 2.6)
project(rfpi)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -std=c11)

# find dependencies
find_package(WiringPi REQUIRED)

# set include directories
set(LIB_DIRS
	src/lib
	)

include_directories(${LIB_DIRS} 
		${WIRINGPI_INCLUDE_DIRS})

# collect source-files
set(LIB_SRCS
	src/lib/rf_module.c
	src/lib/rf_module.h
	src/lib/rf_default_simple_rx.c
	src/lib/rf_default_simple_tx.c	
	)

# define targets
add_library(rfpi SHARED ${LIB_SRCS})

add_executable(tmp src/bin/tmp.c)
target_link_libraries(tmp rfpi)
target_link_libraries(tmp ${WIRINGPI_LIBRARIES})
