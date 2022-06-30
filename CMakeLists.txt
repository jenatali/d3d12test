# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.
cmake_minimum_required(VERSION 3.14)
project(d3d12test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    DirectX-Headers
    GIT_REPOSITORY https://github.com/Microsoft/DirectX-Headers.git
    GIT_TAG main
)
FetchContent_MakeAvailable(DirectX-Headers)

add_executable(d3d12test test.c test_cpp.cpp)
target_link_libraries(d3d12test Microsoft::DirectX-Headers Microsoft::DirectX-Guids)

if (NOT WIN32)
    target_link_libraries(d3d12test dl)
endif()
