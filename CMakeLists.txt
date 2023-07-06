cmake_minimum_required(VERSION 3.10)
project(GraphPartitioningExample CXX)

include(FetchContent)

FetchContent_Declare(
        metis
        GIT_REPOSITORY "https://github.com/scivision/METIS"
        GIT_TAG "v5.1.0.3"
)

FetchContent_Declare(
        pybind11
        GIT_REPOSITORY "https://github.com/pybind/pybind11"
        GIT_TAG "v2.10.4"
)

FetchContent_MakeAvailable(metis pybind11)

# Build metis example
add_executable(partition_example main.cpp)
target_link_libraries(partition_example metis)

# Build pybind module example
pybind11_add_module(pybind11_example bind.cpp)