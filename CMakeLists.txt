cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

add_definitions(-std=c++11)

project(RL-Stats-Review)

include_directories(include)

add_library(DataLib
	include/Data.h
	src/Data.cpp
)

add_executable(RLStatsReview
	src/Start.cpp
)

target_link_libraries(RLStatsReview DataLib)