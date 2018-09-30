CFLAGS= -g -Wall -pedantic
CircuitRouter-SeqSolver: CircuitRouter-SeqSolver.o router.o maze.o grid.o coordinate.o list.o pair.o queue.o vector.o
	gcc $(CFLAGS) coordinate.o grid.o CircuitRouter-SeqSolver.o maze.o router.o lib/list.o lib/pair.o lib/queue.o lib/vector.o -lm -o CircuitRouter-SeqSolver
CircuitRouter-SeqSolver.o: CircuitRouter-SeqSolver.c
	gcc $(CFLAGS) -c CircuitRouter-SeqSolver.c -o CircuitRouter-SeqSolver.o
router.o: router.c router.h
	gcc $(CFLAGS) -c router.c -o router.o
maze.o: maze.c maze.h
	gcc $(CFLAGS) -c maze.c -o maze.o
grid.o: grid.c grid.h
	gcc $(CFLAGS) -c grid.c -o grid.o
coordinate.o: coordinate.c coordinate.h
	gcc $(CFLAGS) -c coordinate.c -o coordinate.o
list.o: lib/list.c lib/list.h
	gcc $(CFLAGS) -c lib/list.c -o lib/list.o
pair.o: lib/pair.c lib/pair.h
	gcc $(CFLAGS) -c lib/pair.c -o lib/pair.o
queue.o: lib/queue.c lib/queue.h
	gcc $(CFLAGS) -c lib/queue.c -o lib/queue.o
vector.o: lib/vector.c lib/vector.h lib/types.h lib/utility.h
	gcc $(CFLAGS) -c lib/vector.c -o lib/vector.o
clean: 
	rm -f *.o lib/*.o CircuitRouter-SeqSolver
