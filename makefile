link: item_int.o list.o main.o
	gcc item_int.o list.o main.o -o list.exe

item_int.o:
	gcc -c item_int.c

list.o:
	gcc -c list.c

main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe
