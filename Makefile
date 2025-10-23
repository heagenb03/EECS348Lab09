CC=g++ #Compiler used
CFLAGS= -c -Wall #Compiler flags

all: main #executable build

main: main.o #Link .o files to executable
	$(CC) -o main main.o

main.o: main.cpp #Link main.o files to main.cpp file
	$(CC) $(CFLAGS) -c main.cpp

clean: #Clean command to remove .o and executable files
	rm -f main *.o