all: application

# compiler
CC = gcc

# where to install
INSTDIR = myapp

# where are inlcude file kept
INCLUDE_APP = include_app/

INCLUDE_LIB = include_lib/

#Option for development
#compile flag
CFLAGS = -g -Wall 
#-fsanitize=address
#-fsanitize=address: building with Address Sanitzer:
# memory access error such as use-after-free and memory leaks

#linking flag
#LDFLAGS = -fsanitize=address -static-libasan
## -static-libasan: link to Asan library

# Local Libraries
MYLIB = mylib.a

application: main.o $(MYLIB)
	$(CC) -o myapp main.o $(MYLIB)

$(MYLIB): $(MYLIB)(execute_command.o) $(MYLIB)(read_write.o) $(MYLIB)(signal_handler.o)


main.o: src_app/main.c include_app/header_app.h 
	$(CC) -I$(INCLUDE_APP) -I$(INCLUDE_LIB) $(CFLAGS) -c src_app/main.c

execute_command.o: src_app/execute_command.c include_app/header_app.h
	$(CC) -I$(INCLUDE_APP) $(CFLAGS) -c src_app/execute_command.c 

read_write.o: src_lib/read_write.c include_lib/header_lib.h 
	$(CC) -I$(INCLUDE_LIB) $(CFLAGS) -c src_lib/read_write.c 

signal_handler.o: src_app/signal_handler.c include_app/header_app.h 
	$(CC) -I$(INCLUDE_APP) $(CFLAGS) -c src_app/signal_handler.c 

#note: -I path to include directory

#clean file 
clean:
	-rm *.o 
	-rm myapp
	-rm mylib.a 