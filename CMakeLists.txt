cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)

project(ExampleGtest LANGUAGES CXX)

# include(FetchContent)
# FetchContent_Declare(
#         googletest
#         GIT_REPOSITORY https://github.com/google/googletest.git
#         GIT_TAG        bf66935e07825318ae519675d73d0f3e313b3ec6 
# )
# FetchContent_MakeAvailable(googletest)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} exampleTestFixture.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::GTest GTest::Main)

# include(GoogleTest)
# gtest_discover_tests(${PROJECT_NAME})