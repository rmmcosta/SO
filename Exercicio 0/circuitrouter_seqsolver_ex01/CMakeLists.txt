cmake_minimum_required(VERSION 3.12)
project(circuitrouter_seqsolver_ex01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    lib/list.c
    lib/list.h
    lib/pair.c
    lib/pair.h
    lib/queue.c
    lib/queue.h
    lib/timer.h
    lib/types.h
    lib/utility.h
    lib/vector.c
    lib/vector.h
    CircuitRouter-SeqSolver.c
    coordinate.c
    coordinate.h
    grid.c
    grid.h
    maze.c
    maze.h
    router.c
    router.h)

add_executable(circuitrouter_seqsolver_ex01 ${SOURCE_FILES})