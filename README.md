# Pipex

## Summary
In the Pipex project at 42, the task was to create a program in C that emulates the Unix pipe mechanism. The program takes input from a file or standard input (stdin), processes it through a series of specified commands, and outputs the result to a file or standard output (stdout).

## Implementation
The program uses system calls such as fork, execve, dup2, and pipe to create a series of child processes connected by pipes. Each child process executes a specific command in the pipeline, and the output of one process becomes the input for the next.

## Basic Usage
The basic functionality involves:

1. Reading input from a file or stdin.

2. Passing the input through multiple commands.

3. Writing the final output to a file or stdout.
## Bonus Features
For the bonus part of the project, additional features and optimizations were implemented to enhance the program's performance and capabilities:

Multiple Pipes: Handling multiple pipes to connect several commands in a chain.

Error Handling: Improved error handling for various edge cases and system call failures.

Efficiency: Optimized process management to reduce overhead and improve execution speed.

Here_doc: Implemented the here_doc functionality to allow input directly from the command line until a specified delimiter is encountered.

## Example

./pipex file1 "cmd1" "cmd2" "cmd3" file2

This command takes input from file1, processes it through cmd1, cmd2, and cmd3, and writes the output to file2.

## Here_Doc Example

./pipex here_doc LIMITER "cmd1" "cmd2" file2

This command allows input to be provided directly from the command line until the LIMITER is encountered, processes it through cmd1 and cmd2, and writes the output to file2.
