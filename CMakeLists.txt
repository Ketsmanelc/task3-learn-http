cmake_minimum_required(VERSION 3.20)
project(Task3_LearnHttp)

set(CMAKE_CXX_STANDARD 14)
set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335)
# The commit hash for 1.7.2. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_executable(Task3_LearnHttp main.cpp)
target_link_libraries(Task3_LearnHttp PRIVATE cpr::cpr)