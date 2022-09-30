all: application

# which compiler
CC = gcc

# where to install
INSTDIR = my_application

# where are inlcude file kept
INCLUDE = include/

#Option for development
CFLAGS = -g -Wall

# Local Libraries
MYLIB = mylib.a

application: main.o $(MYLIB)
	$(CC) -o application main.o $(MYLIB)

$(MYLIB): $(MYLIB)(execute_command.o) $(MYLIB)(read_write.o) $(MYLIB)(signal_handler.o)
main.o: main.c lib_training_exam.h 
execute_command.o: execute_command.c lib_training_exam.h 
read_write.o: read_write.c lib_training_exam.h 
signal_handler.o: signal_handler.c lib_training_exam.h 

#clean 
clean:
	-rm *.o
	-rm application
	-rm *.txt
	-rm mylib.a
	-rm -rf $(INSTDIR)

#install application to directory
install: application
	@if [ -d $(INSTDIR) ]; \
		then \
		mv application $(INSTDIR) &&\
		chmod a+x $(INSTDIR)/application &&\
		chmod og-w $(INSTDIR)/application && \
		echo "Installed in $(INSTDIR)" ;\
	else \
		echo "Sorry, $(INSTDIR) does not exits"; false ;\
	fi
make_directory:
	-mkdir $(INSTDIR)
