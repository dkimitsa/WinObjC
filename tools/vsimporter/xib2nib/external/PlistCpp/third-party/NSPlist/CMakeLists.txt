cmake_minimum_required(VERSION 2.6)
project(NSPlist)

add_library(NSPlist OBJECT src/NSPlist.cpp src/NSPlistLexer.cpp src/NSPlistParser.cpp)
