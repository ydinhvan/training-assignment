all: application

# compiler
CC = gcc

# where to install
INSTDIR = myapp

# where are inlcude file kept
INCLUDE = include/

#Option for development
CFLAGS = -g -Wall 

# Local Libraries
MYLIB = mylib.a

application: main.o $(MYLIB)
	$(CC) -o myapp main.o $(MYLIB)

$(MYLIB): $(MYLIB)(execute_command.o) $(MYLIB)(read_write.o) $(MYLIB)(signal_handler.o)


main.o: src/main.c include/lib_training_exam.h 
	$(CC) -I$(INCLUDE) $(CFLAGS) -c src/main.c

execute_command.o: src/execute_command.c include/lib_training_exam.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c src/execute_command.c 

read_write.o: src/read_write.c include/lib_training_exam.h 
	$(CC) -I$(INCLUDE) $(CFLAGS) -c src/read_write.c 

signal_handler.o: src/signal_handler.c include/lib_training_exam.h 
	$(CC) -I$(INCLUDE) $(CFLAGS) -c src/signal_handler.c 

#note: -I path to include directory

#clean file 
clean:
	-rm *.o 
	-rm myapp
	-rm mylib.a 