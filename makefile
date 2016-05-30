CC= gcc
OBJ= main.o algo.o
Forteresse:	$(OBJ) algo.h
	$(CC) -o Forteresse $(OBJ)

main.o:	main.c algo.h
	$(CC) -c main.c

algo.o: algo.c algo.h
	$(CC) -c algo.c

clean:	
	rm *.o