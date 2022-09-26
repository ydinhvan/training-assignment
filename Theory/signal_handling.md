<h1 style = "text-align:center"> Signal Handling </h1>
### 1. Define
Signal processing defines how a program handles various signal while executes.
Signal like a software interrupt

Ex: A signal can report some asynchronous event outside program : Ctrl+C
### 2. Type of signals
* The C standard defines 6 signal in header file "signal.h"
    - **SIGABRT** - "abort-huy bo" abnormal termination
    - **SIGFPE** - floating point exception
    - **SIGILL** - "illegal- khong hop le" invalid instruction
    - **SIGINT** - "interrupt" interactive attention request sent to the program
    - **SIGSEGV** - "segmentation violation" invalid memory access
    - **SIGTERM** - "terminate", termination request sent to the program
* The standard signal in UNIX (32 signal)
    - **SIGCHLD** - child process sent report dad process when child process finish
### 3. Ignore a signal
syntax: **signal(signal_number, handler_function)**
Note: Signal_number: SIGINT, SIGILL,..
Ex: Handler Ctrl+C  
void sig_handler()
{
    print("Ctrl+C ignored, can not press")
}
in main call function: signal(SIGINT,sig_handler);
### 4. Block signal
- declare a signal handle mask
**syntax**: int sigset_t sigset
Ex: sigset_t my_sigset;
- fill  signal function
**syntax**: int sigfillset(sigset_t* set)
Ex: sigfillset(&my_sigset)
- add set signal function
**syntax**: int sigaddset(sigset_t* set, int signo)
Ex: sigaddset(&my_sigset, SIGINT)
- delete set signal function
**syntax**:int sigdelset(sigset_t* set, int signo)
Ex: sigdelset(@my_sigset, SIGILL)
- empty signal function
**syntax**: int sigemptyset(sigset_t* set)
Ex: sigemptyset(&my_sigset)
- request to block, unblock a signal
**syntax**: int sigprocmask(int how, const sigset_t* set, sigset_t* old set)
Ex: sigprocmask(&my_sigset)
how: SIG_BLOCK, SIG_UNBLOCK, SIG_SETMASK
- check a signal is pending or not
**syntax**:int sigpending(sigset_t* set)
Ex: sigpending(&my_sigset)
