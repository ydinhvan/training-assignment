<h1 style="text-align: center;">GDP Debuger and Cscope</h1>
## 1. GDP Debuger
**Instruction**
* **Step 1**: insert **-g** : on command to enter debug mode
* **Step 2**: typping **gdb #file** : select debug file
* **Step 3**: typinng **b N** : break point at line N
* **Step 4**: typing   **run** : to run debugger
* **Step 5**: typing **print value** to print need value
**continue**: to continue loop
**next**: to next command in file
**quit**: quit debugger 
##2. Cscope
Using Cscope to find function/definition in all C file.
**cscope -R**: to enter Cscope, typing function/definition on modes to find
**ctrl D**: to quit Cscope
Another, using **grep -nrwI "function/definiton"** to fine text.