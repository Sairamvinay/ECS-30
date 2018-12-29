connectn.out: connectn2.o main.o
	gcc -g -Wall -Werror -o connectn.out connectn2.o main.o

connectn2.o: connectn2.c connectn.h
	gcc -g -Wall -Werror -c -o connectn2.o connectn2.c

main.o: main.c connectn.h
	gcc -g -Wall -Werror -c -o main.o main.c

clean:
	rm -f *.o *.out