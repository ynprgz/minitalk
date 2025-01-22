# minitalk

The purpose of this project is to code a small data exchange program using UNIX signals.

## Table of contents

- [Understanding Minitalk](#understanding-minitalk)
- [Resources](#resources)

## Understanding Minitalk
### Allowed functions explanation

from <signal.h>

- signal: Is a function used to handle asynchronous events like interrupts or termination signals.
Takes two paramenters, the signal number and a function pointer to the signal handler.
- sigemptyset: Initializes a signal to exclude all signals. Purpose: Create an empty signal set for
manipulation.
- sigaddset: Adds signal to a signal set. Add specific signal to a set initialized with sigemptyset.
- sigaction: Used to specify a handler for a specific signal, replacing signal for greater flexibility.
- kill: Sends a signal to a process. Takes two params, first(pid) Process ID to which the signal is sent,
second(sig) Signal number.
- getpid: Retrieves the current process ID.
- pause: Suspends the calling process until a signal is received.
- sleep: Suspends the execution of the calling thread for a specified number of seconds(as a param).
- usleep: Suspends execution for a specified number of microseconds.

from <stdlib.h>

- malloc and free: Allocate memory dynamically and free allocated memory.
- exit: Terminates the calling process immediately.

## Resources

- [Beej's Guides](https://beej.us/guide/bgipc/html/split/signals.html#signals)
- [Beej's Guides 2](https://beej.us/guide/bgc/html/split/signal-handling.html#signal-handling)
