cmake_minimum_required(VERSION 3.16)
project(cruzer LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
option(CRUZER_TESTS "Build the Cruzer tests" OFF)
option(CRUZER_PYTHON "Build the Cruzer Python bindings" ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
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

if(CRUZER_PYTHON)
  add_subdirectory(vendor/pybind11)
  pybind11_add_module(pycruzer bindings/python/wrapper.cc)
  target_link_libraries(pycruzer PRIVATE octue_cruzer)
  include(GNUInstallDirs)
  install(TARGETS pycruzer
    LIBRARY DESTINATION .
    COMPONENT pycruzer)
endif()
