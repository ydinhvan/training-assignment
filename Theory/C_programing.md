<h1 style ="text-align: center"> Linux Programing</h1>
### 1. Diffrence between #include<file_name> and #include "file_name"
- #include<file_name>: system header file. It searchs for a file in standard directory: usr/lib,... 
- #inlcude"file_name": header file of own program. normal need path to file.
### 2. Permission
Permission: access option 
syntax: **ower** + **usergroup** + **everyone**
**r** = read; **w** = write; **x** = execute; **-** = no permission

**0** = - = no permission
**1** = -x = execute
**2** = -w- = write
**3** = -wx = write + execute
**4** = r- = read
**5** = r-x = read+execute
**6** = rw- = read + write
**7** = rwx = read + write + execute

Example: chmod 755 

|Ower     |Usergroup  | Everyone |
|---------|-----------|----------|
|7 = rwx  | 5 = r-x   | 5 = r-x  |
|read, write, execute|read, execute| read, execute|  

777: everyone has access to read/write/execute

### 3. GCC option
**-Werror**: show error
**-Wall**: show error and warning
**-l**: linking particular library
**-c**: compile and give object file -> make libraries
**-v**: verbose purpose: show detail
**-g**: turn on gdb debuger
**-o**: create a new file

### 4. Build static library
**Step 1**: Create the object files: (**.c**->**.o**)
Ex: gcc -c src/main.c  -o bin/main.o
    gcc -c src/add.c  -o bin/static/add.o

**Step 2**: Create static library from .o files. (**.o**->**.a**). 
Ex: ar crv bin/static/lib_name.a  bin/static/add.o  bin/static/sum.o

**Step 3**: Link statically

Ex: gcc -o bin/statically-linked   bin/main.o   bin/static/lib_name.o 

**Step 4**: Execute
Ex: ./bin/staticlly-linked

**Note**: 
**-l**: link to access the library 
**-L**: link to folder contain object file
(**no space** between -l and folder) 
### 5. Build shared library

**Step 1**: Create the object files: (**.c**->**.o**)
**Note**: add **-fPIC** flag: (Position Independent Code)  
Ex: gcc -c -fPIC src/main.c  -o bin/shared/main.o
    gcc -c -fPIC src/add.c  -o bin/shared/add.o

**Step 2**: Create static library from .o files. (**.o**->**.a**).
Ex: gcc -shared bin/shared/add.o bin/shared/sum.o -o bin/shared/lib_shared.so  

**Step 3**: Link statically
Ex: gcc -o bin/shared-library bin/main.o bin/shared/lib_shared.so

**step 4**: Execute
Ex: ./shared-library
**
**Step 4**: Use LD_LIBRARY_PATH to use the shared library
Ex: : LD_LIBRARY_PATH= $(pwd)bin/shared bin/use-shared-library

**Step 5**:  Move the shared library to default location
Ex 
sudo mv bin/shared/lib_src.so  /usr/lib
// change permission
sudo chmod 755 /usr/lib/lib_src.so

### 6. String
- Function to get char from **stdin** skip new line **\n** 
  **syntax**: scanf("%m[*^*\n]%*c", str); 
  **meaning**:
  **%m**: malloc memory,
  **[^\n]**: skip if meet \n,
  **%*c**: get single char from stdin
- Function to get string from **stdin**
  **syntax**: 
  char* str= (char*)malloc(256)
  // check if memory point to NULL
  if (str == NULL)
  {
    printf("No memory\n");
    return;
  }
  // Get string from stdin
  gets(str, 256, stdin);
  // Remove newline, if there.
  if ((strlen(str)>0) && (str[strlen(str)-1] == '\n'))
  {
    str[strlen(str)-1] = '\0';
  }
  