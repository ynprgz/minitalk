# minitalk

The purpose of this project is to code a small data exchange program using UNIX signals.

## Table of contents

- [Understanding Minitalk](#understanding-minitalk)
- [Resources](#resources)

## Understanding Minitalk
### Allowed functions explanation

from <signal.h> and <unistd.h>

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


### SIGUSR1 and SIGUSR2

Are all the signals predefined? What if you want to send a signal that has significance that only you understand to a process? There are two signals that aren’t reserved: SIGUSR1 and SIGUSR2. You are free to use these for whatever you want and handle them in whatever way you choose.

### Bonus - Unicode Characters

- The server acknowledges every message received by sending back a signal to the
client and Unicode characters support.

What are Unicode Characters?

- Unicode is a global standard for text encoding, allowing us to represent text from many different languages and symbol sets using unique code points.

- It is crucial for modern computing, web development, and internationalization, ensuring that text is consistent and universally readable across devices and platforms.

- UTF-8 (Unicode Transformation Format - 8-bit) is one of the most widely used character encoding schemes for representing Unicode characters in binary form. It is a variable-length encoding that can represent any character in the Unicode standard, while being backward-compatible with ASCII.


## Resources

- [Beej's Guides](https://beej.us/guide/bgipc/html/split/signals.html#signals)
- [Beej's Guides 2](https://beej.us/guide/bgc/html/split/signal-handling.html#signal-handling)
- Just use 'man <function name>'.
