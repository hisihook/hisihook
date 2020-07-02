cmake_minimum_required(VERSION 3.15)
project(hisihook)

SET(CMAKE_SYSTEM_NAME linux)
SET(CMAKE_SYSTEM_PROCESSOR "arm")
SET(CMAKE_FIND_ROOT_PATH  /opt/hisi-linux/x86-arm/arm-himix200-linux/arm-himix200-linux/)
SET(CMAKE_CROSSCOMPILING true)
SET(CMAKE_C_COMPILER "arm-himix200-linux-gcc")
SET(CMAKE_CXX_COMPILER "arm-himix200-linux-g++")
SET(CMAKE_AR "arm-himix200-linux-ar")
SET(CMAKE_RANLIB "arm-himix200-linux-ranlib")
SET(CMAKE_STRIP "arm-himix200-linux-strip")
SET(TARGET_FILE HiSilicon)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-std=c++11")
add_compile_options(-Wall -mcpu=cortex-a53 -mfloat-abi=softfp -mfpu=neon-vfpv4 -fno-aggressive-loop-optimizations -ldl -ffunction-sections -fdata-sections -O2 -fstack-protector-strong)
include_directories(include sdk_include)


add_library(hisihook SHARED
        library.cpp
        plthook_elf.c
        )