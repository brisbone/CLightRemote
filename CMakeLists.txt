cmake_minimum_required(VERSION 3.13)
project(CLightRemote)

set(CMAKE_CXX_STANDARD 14)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

include_directories("/home/brisbone/projects/qtcreator/5.12.2/gcc_64/include/")
add_executable(CLightRemote main.cpp Getsensor.h Getsensor.cpp ui_mainwindow.h mainwindow.h mainwindow.cpp)
target_link_libraries(CLightRemote Qt5::Widgets)

set(CMAKE_CXX_STANDARD_LIBRARIES -lcurl)

set(CMAKE_CXX_FLAGS -fPIC)