CC = gcc
CFLAGS = -O4 
LIBS = 
PROG = lista.exe
PROG_D = lista_debug
SOURCE = main.c lista.c


build: $(PROG)
	@echo Done
	
$(PROG): main.o lista.o
	$(CC) -o $(PROG) main.c lista.c $(CFLAGS) $(LIBS)
	
main.o : main.c
	$(CC) $(CFLAGS) -c main.c $(LIBS)

lista.o :  lista.c
	$(CC) $(CFLAGS) -c lista.c $(LIBS)
	
	
debug: $(PROG_D)
	@echo Done Debug.
	
$(PROG_D): $(SOURCE)
	$(CC) -o $(PROG_D) $(SOURCE) -g
	
run:
	./$(PROG) 

run_debug:
	./$(PROG_D)

clean:
	rm -rf *.o $(PROG) *.~
	@echo Done Clean