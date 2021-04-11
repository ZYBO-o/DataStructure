cmake_minimum_required(VERSION 3.15)
project(DataStructure_Realization)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructure_Realization main.cpp HeadCodes/Object/Object.h HeadCodes/Exception/Exception.h SourceCodes/Exception.cpp HeadCodes/SmartPointer/SmartPointer.h SourceCodes/Object.cpp HeadCodes/LineStructure/List.h HeadCodes/LineStructure/SeqList.h HeadCodes/LineStructure/StaticList.h HeadCodes/LineStructure/DynamicList.h HeadCodes/LineStructure/Array.h HeadCodes/LineStructure/StaticArray.h HeadCodes/LineStructure/DynamicArray.h HeadCodes/LineStructure/LinkList.h HeadCodes/LineStructure/StaticLinkList.h HeadCodes/SmartPointer/Pointer.h HeadCodes/SmartPointer/SharedPointer.h HeadCodes/Sort/Sort.h HeadCodes/Recursion/List_Case.h HeadCodes/Recursion/Recursion_List.h HeadCodes/Recursion/Merge_Lists.h Test/TestString.h HeadCodes/String/String.h SourceCodes/String.cpp)