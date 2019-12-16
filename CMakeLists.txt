cmake_minimum_required(VERSION 3.15)
project(flightsimulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(flightsimulator main.cpp Command.h Parser.h OpenDataServer.cpp OpenDataServer.h CreateVarCommand.h
        ConnectClientCommnad.cpp SleepCommand.cpp SleepCommand.h CreateVarCommand.cpp ConnectClientCommand.h Var.cpp SetCommand.cpp SetCommand.h Interpreter.cpp Interpreter.h Expression.h
        ex1.cpp ex1.h Parser.cpp SymbolTable.h SymbolTable.cpp printCommand.cpp printCommand.cpp)