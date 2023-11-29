cmake_minimum_required(VERSION 3.26)
project(GTest_CPP_Module05 CXX)

set(CMAKE_CXX_STANDARD 98)
find_package(GTest REQUIRED)
enable_testing()

# includesディレクトリを追加
file(GLOB INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/*/includes")
include_directories(${INCLUDE_DIRS})

# main.cppを除いてソースファイルを追加
file(GLOB_RECURSE SOURCE_FILES "${PROJECT_SOURCE_DIR}/*/srcs/*.cpp")
list(FILTER SOURCE_FILES EXCLUDE REGEX ".*/main\\.cpp$")

add_executable(cpp_test ${PROJECT_SOURCE_DIR}/tests/test.cpp ${SOURCE_FILES})
target_link_libraries(cpp_test
        PRIVATE
        $<IF:$<VERSION_GREATER_EQUAL:${CMAKE_VERSION},3.20>,
        GTest::gtest GTest::gtest_main,
        GTest::GTest GTest::Main
        >
)

# GTestに単体テストを追加
include(GoogleTest)
gtest_discover_tests(cpp_test)