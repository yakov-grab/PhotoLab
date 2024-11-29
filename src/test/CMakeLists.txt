cmake_minimum_required(VERSION 3.5)
project(PhotoLab_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(GTest REQUIRED)


include_directories( 
${CMAKE_SOURCE_DIR}/model
)

add_subdirectory(googletest-main)

add_executable(
  ${PROJECT_NAME}
  testing.cpp
  ../model/model.cpp
  ../model/model.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets gtest gtest_main)

add_test(NAME all COMMAND ${PROJECT_NAME})
