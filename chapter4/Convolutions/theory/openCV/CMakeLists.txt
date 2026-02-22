cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(EXEC "Build Executable" ON)
option(BENCH "Build Benchmark" OFF)

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

if(NOT Eigen3_FOUND)
    message(FATAL_ERROR "Eigen3 not found. Please install it using: sudo apt-get install libeigen3-dev -y")
endif()

if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found. Please install it using: sudo apt-get install libopencv-dev g++ make -y")
endif()

if(EXEC)
    file(GLOB SOURCES "./*.cpp")
    foreach(source_file ${SOURCES})
        get_filename_component(executable_name ${source_file} NAME_WE)
        add_executable(${executable_name} ${source_file})
        target_link_libraries(${executable_name} Eigen3::Eigen ${OpenCV_LIBS})
        set_target_properties(${executable_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/")
    endforeach()
endif()