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

|   User Space |    Kernel Space|
|:-------------|:---------------| 
| * Where normal user process run| * Where the code of kernel is stored| 
| * Access only to a limited part of memory| * Access to all of the memory|
|* Access kernel via systemcall||

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
* **Note**: process will sleep when call an systemcall -> don't use in case write/read high speed
#4 File system

![File System](https://i.pinimg.com/originals/26/6e/91/266e91442c5a1ce2ff5b2852e912fff4.png)

**/bin** : User binaries
**/boot** : Boot loader file
**/dev** : Device file
**/proc** : Process infomation
**/sbin** : System binaries
**/etc** : configuration
**/srv** : Service Data
**/home** : Home directory
**/lib** : System libraries
**/tmp** : Temporary files
**/media** : Removable Devices
**/usr** : User programs
**/mnt** : Mount Directory
**/var** : Variable files
**/opt** : Optional add-on Apps


