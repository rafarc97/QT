cmake_minimum_required(VERSION 3.14)

project(Threads_Runnable LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Threads_Runnable
  main.cpp
  tasknumber.cpp
  tasknumber.h
)
target_link_libraries(Threads_Runnable Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS Threads_Runnable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
