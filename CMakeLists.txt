cmake_minimum_required(VERSION 3.15)
project(kate VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/text/parser.cpp
    src/directories/create_language_directories.cpp
    src/directories/functions.cpp
    src/commands/building.cpp
    src/commands/new.cpp
    src/commands/help.cpp
)

add_executable(kate ${SOURCES})

# Более надежная проверка на Release (работает и для MinGW, и для GCC)
if(CMAKE_BUILD_TYPE MATCHES "Release|ReleaseWithDebInfo")
    if(MSVC)    
        target_compile_options(kate PRIVATE /O2)
    else()
        target_compile_options(kate PRIVATE -O3)
    endif()
endif()

if(WIN32 AND NOT MSVC)
    target_link_options(kate PRIVATE "-static")
endif()