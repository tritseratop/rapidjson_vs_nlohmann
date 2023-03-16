# CMakeList.txt : CMake project for nlohmann_benchmark, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (nlohmann_benchmark "main.cpp" "values_description.cpp" "utility.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET nlohmann_benchmark PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(nlohmann_benchmark PUBLIC ${CMAKE_SOURCE_DIR})
