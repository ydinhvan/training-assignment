<h1 style="text-align: center;">LINUX BASIC</h1>
# 1. Architecture
* User space
    * Application
        * Libraries
        * System Deamon
        * Shells
        * Tools
    * Operating System
* Kernel Space
    * Kernel
    * Hardware

# 2. Main function
* System Call Interface(SCI): provide the means to perform function call from user space into kernel.
* Process Management(PM): focus on the execution of processes. 
* Virtual File System(VFI): provide a switching layer betwen the SCI anf the file systems supported by the kernel.
* Memory Management(MM):
* Network Stack(NS):
* Arch:
* Device Drivers: 
![Architecture](https://developer.ibm.com/developer/default/articles/l-linux-kernel/images/figure3.jpg)

#3. Systemcall
* **Definition**: Systemcall is a computer program requests a service from the kernel of operating system. A systemcall is a way for a program to interact with oprating system. System call provides the services of the operating system to the user programs via **Application Program Interface(API)**
![Flowchart](https://upload.wikimedia.org/wikipedia/commons/7/76/System_call_interface.jpg)
