cmake_minimum_required(VERSION 3.22)
project(words VERSION 1.0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
    add_compile_options(-fPIC)
endif()

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG a3692678743245c3baf745250292fdfba682dafd # 2022-06-20
)
FetchContent_MakeAvailable(Catch2)

add_executable(words
    main.cpp
    words.cpp
    words.h
)

add_executable(words_tests
    words.cpp
    words_test.cpp
)

target_link_libraries(words_tests PRIVATE Catch2::Catch2WithMain)
enable_testing()
include(Catch)
catch_discover_tests(words_tests)
