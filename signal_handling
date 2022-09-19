#Signal Handling
## 1. Define
signal processing defines how a program handles various signal while executes.
Signal like a software interrupt

Ex: A signal can report some asynchronous event outside program : Ctrl+C
## 2. Type of signals
The C standard defines 6 signal in header file "signal.h"
- SIGABRT - "abort-huy bo" abnormal termination
- SIGFPE - floating point exception
- SIGILL - "illegal- khong hop le" invalid instruction
- SIGINT - "interrupt" interactive attention request sent to the program
- SIGSEGV - "segmentation violation" invalid memory access
- SIGTERM - "terminate", termination request sent to the program
The standard signal in UNIX
- SIGCHLD - child process sent report dad process when child process finish
# 3. Ignore a signal
syntax: signal(signal_number, SIG_IGN)
Note: Signal_number: SIGINT, SIGILL,..
# 4. Block signal
- declare a signal handle mask
Ex: sigset_t my_sigset;
- fill  signal function
int sigfillset(sigset_t* set)
Ex: sigfillset(&my_sigset)
- add set signal function
int sigaddset(sigset_t* set, int signo)
Ex: sigaddset(&my_sigset, SIGINT)
- delete set signal function
int sigdelset(sigset_t* set, int signo)
Ex: sigdelset(@my_sigset, SIGILL)
- empty signal function
int sigemptyset(sigset_t* set)
Ex: sigemptyset(&my_sigset)
- request to block, unblock a signal
int sigprocmask(int how, const sigset_t* set, sigset_t* old set)
Ex: sigprocmask(&my_sigset)
how: SIG_BLOCK, SIG_UNBLOCK, SIG_SETMASK
- check a signal is pending or not
int sigpending(sigset_t* set)
Ex: sigpending(&my_sigset)
