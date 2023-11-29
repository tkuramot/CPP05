cmake_minimum_required(VERSION 3.26)
project(cpp-module CXX)

set(PROGRAM cpp-module)

# Google Testの不要なキャッシュ変数をオフにしておく
option(BUILD_GMOCK "Builds the googlemock subprojects" OFF)
option(INSTALL_GTEST "Enables installation of googletest" OFF)

enable_testing()

# Google Testをこのプロジェクトに組み込む
add_subdirectory(${PROJECT_SOURCE_DIR}/third-party/googletest)

# main.cppを除いてソースファイルを追加
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/*/srcs/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX ".*/main\\.cpp$")
# テストのソースファイルを追加
file(GLOB TEST_SOURCES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

add_executable(${PROGRAM} ${TEST_SOURCES} ${SOURCES})

# includesディレクトリを追加
file(GLOB INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/*/includes")
target_include_directories(${PROGRAM}
        PRIVATE
        ${INCLUDE_DIRS}
)

# Google Testをリンク
target_link_libraries(${PROGRAM}
        PRIVATE
        gtest_main
)
target_include_directories(${PROGRAM}
        PUBLIC
        include
        third-party/googletest/googletest/include
        third-party/googletest/googlemock/include
)