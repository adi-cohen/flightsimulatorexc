cmake_minimum_required(VERSION 3.15)
project(flightsimulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(flightsimulator main.cpp Command.h Parser.h OpenDataServer.cpp OpenDataServer.h connectClientCommnad.h
        connectClientCommnad.cpp sleepCommand.cpp sleepCommand.h symbolTable.h)