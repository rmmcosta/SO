programaPai: programaPai.o programaFilho
	gcc programaPai.o -o programaPai
programaPai.o: programaPai.c
	gcc -c programaPai.c -o programaPai.o
programaFilho: programaFilho.o
	gcc programaFilho.o -o programaFilho
programaFilho.o: programaFilho.c
	gcc -c programaFilho.c -o programaFilho.o

clean:
	rm *.o programaFilho programaPai