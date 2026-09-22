cmake_minimum_required(VERSION 3.15)
project(ParallelRenderer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# flag ottimizzazione M1
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -ffast-math -mcpu=apple-m1")

if(APPLE AND CMAKE_CXX_COMPILER_ID MATCHES "AppleClang|Clang")
    find_program(BREW_EXECUTABLE brew)
    if(BREW_EXECUTABLE)
        execute_process(
            COMMAND "${BREW_EXECUTABLE}" --prefix libomp
            OUTPUT_VARIABLE LIBOMP_ROOT
            OUTPUT_STRIP_TRAILING_WHITESPACE
            ERROR_QUIET
        )
    endif()

    if(LIBOMP_ROOT)
        set(OpenMP_ROOT "${LIBOMP_ROOT}")
        set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp")
        set(OpenMP_CXX_INCLUDE_DIR "${LIBOMP_ROOT}/include")
        set(OpenMP_CXX_LIBRARY "${LIBOMP_ROOT}/lib/libomp.dylib")
    endif()
endif()

find_package(OpenMP REQUIRED)

add_executable(renderer src/main.cpp)
target_link_libraries(renderer PRIVATE OpenMP::OpenMP_CXX)