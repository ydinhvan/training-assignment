<h1 style="text-align: center;">Shellscript and Makefile</h1>
## 1. Shellscript
**Definition**: save the command line in a text file and exceute this text file
**Instruction**
* **Step 1**: select the interpreter: **#!bin/bash**
* **Step 2**: write comment
* **step 3**: change permission 
	* **+x** : write
	* **+r** : read
	* **+x** : exceute
**Ex:**
	#!/bin/bash
	rm exam.txt             // remove file exam.txt
## 2. Makefile
![Makefile Structure](https://hocarm.org/content/images/2020/04/makefilerule-e1489805882799.png)    

* **Target**: target file, output after compile
* **Dependency**: the files need to compile
* **Tab**: a tab space
* **Action**: command to create target file

a. Makefile example
Descript: source file contain 3 file: main.c, 2.c and 3.c.

**main.c**: #include"a.h"
**2.c**: #include"a.h" ; #include"b.h"
**3.c**: #include"b.h" ; #include"c.h"

**Makefile**
\# define target
all: myapp

\# using Macro to define compiler
CC = gcc

\# where include file: current directory
INCLUDE = .

\# Option for develop: 
-g: gdb debugger; 
-Wall: show warning and error if there;  
-ansi: standard C version
CFLAGS = -g -Wall -ansi

\# Option for release
-o: create file
CFLAGS = -o -Wall -ansi

\# where want to install application: /usr/local/bin
INSTDIR = /usr/local/bin

\# Local library
MYLIB = mylib.a

myapp: main.o \$(MYLIB)
	\$(CC) -o myapp main.o \$(MYLIB)

\$(MYLIB): \$(MYLIB)(2.o)  \$(MYLIB)(3.o)
main.o: main.c a.h
2.o: 2.c a.h b.h
3.o: 3.c b.h c.h

\# clean all .o file
clean: 
	-rm *.o

\# install application in other directory
install:
	@if [ -d \$(INSTDIR) ]; \
		then \
		cp myapp \$(INSTDIR) && \
		chmod a+x \$(INSTDIR)/myapp && \
		chmod og-w \$(INSTDIR)/myapp && \
		echo "Installed myapp in $(INSTDIR)" ;\
	else
		echo "\$(INSTDIR) does not exist"; false; \

b. Note
- Save makefile:
    - Makefile: only call make to execute
    - other name: call: make -f name to execute
- Syntax: 
    - call **-** after call command of system
    - blank line between command
    - **-I**: path to including directory
## 3. Makefile and Shellscript
|Makefile |Shellscript|
|---------|-----------|
|just build when the file changed-> save time| always build all file  |