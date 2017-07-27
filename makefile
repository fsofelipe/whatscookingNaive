CC=gcc
CFLAGS= -w -l json

cuisine:
	$(CC) main.c jsonParser.c cuisine.c -o teste $(CFLAGS)
	./teste

clear:
	rm -f teste
	rm -f *.o
	clear
