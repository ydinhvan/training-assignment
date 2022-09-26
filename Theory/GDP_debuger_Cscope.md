<h1 style="text-align: center;">GDP Debuger and Cscope</h1>
## 1. GDP Debuger
**Instruction**
* **Step 1**: insert **-g** : on command to enter debug mode
* **Step 2**: typing **gdb file_name** : select debug file
* **Step 3**: typing **b N** : break point at line N
* **Step 4**: typing **run** : to run debugger
* **Step 5**: typing **print value** to print need value
* **Step 6**: typing **step** to go to called function
* **Step 6**: typing **continue**: to continue loop
* **Step 6**: typing **next**: to next command in file
* **Step 6**: typing **quit**: quit debugger 
##2. Cscope
Using Cscope to find function/definition in all C file.
**cscope -R**: to enter Cscope, typing function/definition on modes to find
**ctrl D**: to quit Cscope
Another, using **grep -nrwI "function/definiton"** to fine text.