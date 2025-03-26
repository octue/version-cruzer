cmake_minimum_required(VERSION 3.16)
project(cruzer VERSION 0.0.1 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
option(CRUZER_TESTS "Build the Cruzer tests" OFF)

find_package(Core REQUIRED)

if(PROJECT_IS_TOP_LEVEL)
  sourcemeta_target_clang_format(SOURCES
    src/*.h src/*.cc test/*.h test/*.cc bindings/*.cc)
endif()

add_subdirectory(src)

if(CRUZER_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()
