cmake_minimum_required(VERSION 3.12)
project(SO)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/list.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/list.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/pair.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/pair.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/queue.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/queue.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/timer.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/types.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/utility.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/vector.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/lib/vector.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/CircuitRouter-SeqSolver.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/coordinate.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/coordinate.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/grid.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/grid.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/maze.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/maze.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/router.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 modificado/router.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/list.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/list.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/pair.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/pair.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/queue.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/queue.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/timer.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/types.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/utility.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/vector.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/lib/vector.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/CircuitRouter-SeqSolver.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/coordinate.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/coordinate.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/grid.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/grid.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/maze.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/maze.h"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/router.c"
    "Exercicio 0/circuitrouter_seqsolver_ex01 original/router.h"
    "Livro Sistemas Operativos/exec.c"
    "Livro Sistemas Operativos/execve.c"
    "Livro Sistemas Operativos/fork.c"
    "Livro Sistemas Operativos/myecho.c"
    "Livro Sistemas Operativos/otherThread.c"
    "Livro Sistemas Operativos/otherThread2.c"
    "Livro Sistemas Operativos/simpleFork.c"
    Testes/CircuitRouterTest/lib/list.c
    Testes/CircuitRouterTest/lib/list.h
    Testes/CircuitRouterTest/lib/pair.c
    Testes/CircuitRouterTest/lib/pair.h
    Testes/CircuitRouterTest/lib/queue.c
    Testes/CircuitRouterTest/lib/queue.h
    Testes/CircuitRouterTest/lib/types.h
    Testes/CircuitRouterTest/lib/utility.h
    Testes/CircuitRouterTest/lib/vector.c
    Testes/CircuitRouterTest/lib/vector.h
    Testes/CircuitRouterTest/CircuitRouter-SeqSolver.c
    Testes/CircuitRouterTest/coordinate.c
    Testes/CircuitRouterTest/coordinate.h
    Testes/CircuitRouterTest/grid.c
    Testes/CircuitRouterTest/grid.h
    Testes/CircuitRouterTest/maze.c
    Testes/CircuitRouterTest/maze.h
    Testes/mainArgsTest.c
    Testes/mainArgsTest2.c
    Testes/mainArgsTest3.c
    Testes/snprintfTest.c)

add_executable(SO ${SOURCE_FILES})