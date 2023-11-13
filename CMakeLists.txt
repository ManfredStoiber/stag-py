#cmake_minimum_required(VERSION 3.20)
project(pyStag)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()

MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -w  ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -w ")

# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)


add_compile_options(-std=c++11 -fPIC -O3)
#add_compile_options(-fPIC )


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV 4 REQUIRED)


file(GLOB SRC_FILE1 "stag/*.c*")
file(GLOB SRC_FILE2 "stag/ED/*.c*")

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    stag/
    stag/ED/
)
add_library(
    LibStag STATIC
    ${SRC_FILE1}
    ${SRC_FILE2}
)
target_link_libraries(
    LibStag
    ${OpenCV_LIBS}
)


set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


find_package(NumPy REQUIRED)

add_subdirectory(extern/pybind11)
include_directories("extern/pybind11/include")
include_directories("extern/pybind11_opencv_numpy")


# for pybind11 

pybind11_add_module(pyStag 
pyStag.cpp
extern/pybind11_opencv_numpy/ndarray_converter.cpp
)

target_link_libraries(pyStag PRIVATE
${OpenCV_LIBS}
LibStag
)

# for c++ 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/app)

add_executable(
    testrun
    main.cpp
)

target_link_libraries(
    testrun
    LibStag
)
