CFLAGS = -g -Wall -pedantic
snprintfTest: snprintfTest.o
	gcc snprintfTest.o -o snprintfTest
snprintfTest.o: snprintfTest.c	
	gcc $(CFLAGS) -c snprintfTest.c -o snprintfTest.o
clean:
	rm *.o *.exe