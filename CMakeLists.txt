##################################################################################
# "THE ANY BEVERAGE-WARE LICENSE" (Revision 42 - based on beer-ware
# license):
# <dev@layer128.net> wrote this file. As long as you retain this notice
# you can do whatever you want with this stuff. If we meet some day, and
# you think this stuff is worth it, you can buy me a be(ve)er(age) in
# return. (I don't like beer much.)
#
# Matthias Kleemann
##################################################################################

##################################################################################
# Sample CMakeLists.txt for a simple AVR project based on the toolchain
##################################################################################

cmake_minimum_required(VERSION 2.8)

### TOOLCHAIN SETUP AREA #################################################
# Set any variables used in the toolchain prior project() call. In that
# case they are already set and used.
##########################################################################

##################################################################################
# tools to be used for programming the AVR
##################################################################################
set(AVR_UPLOADTOOL avrdude)
set(AVR_PROGRAMMER USBasp)
set(AVR_UPLOADTOOL_PORT usb)
# AVR and fuses needs to be set
set(AVR_MCU atmega8)
set(AVR_H_FUSE 0xd9)
set(AVR_L_FUSE 0xc3)

### END TOOLCHAIN SETUP AREA #############################################
include(cmake-lists-files/generic-gcc-avr.cmake)
include(cmake-lists-files/custom-avr.cmake)

##########################################################################
# name your project
##########################################################################
project(clion_avr C)

##################################################################################
# needs to be defined for AVR toolchain
##################################################################################
set(MCU_SPEED "8000000UL")

##################################################################################
# add all sources and headers from ./src
##################################################################################
file(GLOB_RECURSE SRC_C_FILES ${PROJECT_SOURCE_DIR}/src/*.c)
file(GLOB_RECURSE SRC_CXX_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

##################################################################################
# add AVR executable
##################################################################################
add_avr_executable(
        ${PROJECT_NAME}
        ${SRC_C_FILES} ${SRC_CXX_FILES} ${SRC_HEADERS}
)

##################################################################################
# add AVR library
##################################################################################
#add_avr_library(
#        <library-name>
#        <sources> <headers>
#)

##################################################################################
# link library to executable
# NOTE: It needs to be the elf target.
##################################################################################
# target_link_libraries(<executable-name>-${AVR_MCU}.elf <library-name>-${AVR_MCU})
# OR easier

#find_library(C_LIB c)
#message(STATUS "avr-libc: ${C_LIB}")
#
#avr_target_link_libraries(${PROJECT_NAME} ${C_LIB})

#target_link_libraries(<executable-name> <library-name> <some-external-libary>)

include_directories("/usr/local/Cellar/check/0.12.0/include")
include_directories("/usr/local/Cellar/simavr/HEAD-6660aba/include/simavr")