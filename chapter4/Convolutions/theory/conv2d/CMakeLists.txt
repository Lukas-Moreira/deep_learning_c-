cmake_minimum_required(VERSION 3.10)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

option(EXEC "Build executables !" ON)
option(BENCH "Build benchmarks" OFF)

find_package(Eigen3 REQUIRED)

if(NOT Eigen3_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        Eigen3
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.4.0
    )
    FetchContent_MakeAvailable(Eigen3)
endif()

if(EXEC)
    file(GLOB SOURCES "./*.cpp")

    foreach(source_file ${SOURCES})
        get_filename_component(executable_name ${source_file} NAME_WE)
        add_executable(${executable_name} ${source_file})
        target_link_libraries(${executable_name} Eigen3::Eigen)
    endforeach()
endif(EXEC)

if(BENCH)
    find_package(benchmark CONFIG REQUIRED)

    file(GLOB SOURCES "benchmarks/*.cpp")

    foreach(source_file ${SOURCES})
        get_filename_component(executable_name ${source_file} NAME_WE)
        add_executable(${executable_name} ${source_file})
        target_include_directories(${executable_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
        target_link_libraries(${executable_name} PRIVATE Eigen3::Eigen benchmark::benchmark benchmark::benchmark_main)
        set_target_properties(${executable_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/benchmarks")
        
    endforeach()
endif()
