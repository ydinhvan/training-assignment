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

## 3. Makefile and Shellscript
|Makefile |Shellscript|
|---------|-----------|
|just build the changed file -> save time| build all file  |