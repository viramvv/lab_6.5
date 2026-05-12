cmake_minimum_required(VERSION 3.10)
project(DequeProject)

set(CMAKE_CXX_STANDARD 17)

# --- Налаштування Google Test ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- 1. Виконуваний файл для основної програми (main.cpp) ---
add_executable(MainApp main.cpp)

# --- 2. Виконуваний файл для тестів (UnitTest.cpp) ---
add_executable(UnitTest UnitTest.cpp)
target_link_libraries(UnitTest gtest_main)

# Реєстрація тестів у системі
include(GoogleTest)
gtest_discover_tests(UnitTest)