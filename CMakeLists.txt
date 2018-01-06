cmake_minimum_required(VERSION 3.9)
project(Optimization)

set(CMAKE_CXX_STANDARD 17)

add_executable(Optimization main.cpp)

include_directories(/Applications/CPLEX_Studio128/cplex/include)
include_directories(/Applications/CPLEX_Studio128/concert/include)
add_definitions(-DIL_STD)

#target_include_directories(Optimization -I/Applications/CPLEX_Studio128/cplex/include)

target_link_libraries(Optimization -L/Applications/CPLEX_Studio128/concert/lib/x86-64_osx/static_pic)
target_link_libraries(Optimization -L/Applications/CPLEX_Studio128/cplex/lib/x86-64_osx/static_pic)
target_link_libraries(Optimization -lilocplex -lconcert)
target_link_libraries(Optimization -lilocplex -lconcert -lcplex -lm -lpthread)

