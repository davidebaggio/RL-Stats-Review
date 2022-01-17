cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

add_definitions(-std=c++11)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

project(RL-Stats-Review)

include_directories(include)

add_library(DataLib
	include/Data.h
	include/Pos.h
	include/HeatMapPrompt.h
	src/Data.cpp
	src/HeatMapPrompt.cpp
)

add_executable(RLStatsReview
	src/Start.cpp
)

target_link_libraries(RLStatsReview DataLib)