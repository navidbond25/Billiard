cmake_minimum_required(VERSION 3.6)
project(Billiard)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH /home/sepehr007/Desktop/QT5.8/5.8/gcc_64/)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Network Multimedia)

set(cmake_prefix_path ${qt5_base_dir}/lib/cmake)

set(SOURCE_FILES main.cpp SourceFiles/Login.cpp HeaderFiles/Login.h SourceFiles/UserTable.cpp HeaderFiles/UserTable.h SourceFiles/Matching.cpp HeaderFiles/Matching.h SourceFiles/Server.cpp HeaderFiles/Server.h HeaderFiles/Connection.h SourceFiles/Connection.cpp HeaderFiles/ServerTable.h SourceFiles/ServerTable.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network Qt5::Multimedia)