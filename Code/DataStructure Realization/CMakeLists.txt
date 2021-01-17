cmake_minimum_required(VERSION 3.15)
project(DataStructure_Realization)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructure_Realization main.cpp HeadCodes/Object.h HeadCodes/Exception.h SourceCodes/Exception.cpp HeadCodes/SmartPointer.h SourceCodes/Object.cpp HeadCodes/List.h HeadCodes/SeqList.h HeadCodes/StaticList.h HeadCodes/DynamicList.h)