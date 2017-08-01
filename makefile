CC=gcc

CFLAGS= -w -l json -I/usr/local/Cellar/json-c/0.12/include/json-c/

run:
	$(CC) main.c naive.c cuisine.c jsonParser.c -o teste $(CFLAGS)
	./teste

clear:
	rm -f teste
	rm -f *.o
	clear
