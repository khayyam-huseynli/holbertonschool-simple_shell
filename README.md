## Simple Shell
## holbertonschool-simple_shell

![logo](https://opensource.com/sites/default/files/lead-images/bash_command_line.png)

## Description
   As the first trimester final project our purpose on that, is to create simple UNIX command-line interpreter (shell) that displays a prompt and executes simple 
   commands entered by the user. This project demonstrates the basic functionality of a shell, such as reading user input, forking processes, and executing commands
   using execve.

## Compilation
   To run the shell:

   First compile your program using the following compiling command:

```bash
 $ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
```
  Then execute your program by:
```
```bash
./simple_shell
```

## How will it work ?

   After the execution of your program shell displays a prompt #cisfun$, awaiting user input.
   The user can enter simple commands, and the shell will attempt to execute them. If the command cannot be executed, an error message is displayed, and the prompt is
   shown again.

## Features of the program

  - Prompt: Displays a prompt #cisfun$ and waits for the user to enter a command. 
  - Command Execution: Executes a single-word command by forking a new process and using execve(). 
  - Error Handling: If the command cannot be executed, an error message is displayed. 
  - End-of-File Handling: The shell exits gracefully when Ctrl+D (EOF) is encountered. 
  - Process Management: Waits for child processes to complete before continuing.

## Steps of the program
     The shell operates in a loop with the following steps:

   - Display Prompt: Prints the prompt #cisfun$ to indicate that the shell is ready to receive a command.
   - Read Input: Uses getline() to read the command line entered by the user.
   - Handle EOF: If Ctrl+D (EOF) is entered, the shell exits.
   - Fork Process: Creates a new process using fork().
   - Execute Command: In the child process, uses execve() to execute the command. If execution fails, prints an error message and exits.
   - Wait for Completion: In the parent process, waits for the child to complete.
   - Loop: Repeats the process, displaying the prompt again.

## Error Handling
- If execve() cannot find or execute the specified command, the shell displays an error message, including a brief explanation of the error (using perror()), and then
  returns to the prompt.

- If the fork() call fails, the shell exits with an error message.

## How to Exit ?
  To exit the shell, you can either:

- Press Ctrl+D to trigger the "end-of-file" condition.
- Type exit and press Enter (this will likely result in an error message since exit isn't implemented as a built-in command, but it indicates the intention to exit).

## Collaborators of the project

- [Khayyam Huseynli](https://github.com/khayyam-huseynli)
- [Shukufa Bayramzada](https://github.com/shukufabayramzada)
- [Amina Yusifova](https://github.com/aminayusufova)
