
# Simple Shell Project
This project is a simple UNIX command interpreter created using the C programming language for Holberton School.
# Overview
The simple shell is a basic command-line interpreter that allows users to execute commands in a UNIX-like environment. The shell provides a prompt where users can enter commands, and it executes those commands by creating child processes.
# Code Structure
The main functionality of the shell is implemented in the main.c file, with additional functions in separate files for better modularity.
### main.c
- The main function initializes the shell and enters into a loop to continuously read and execute user commands
- It checks if the input is coming from a terminal and prints a prompt accordingly.
- The exit_and_env function handles built-in commands like exit and env.
- User commands are processed through the pre_execute function, which includes splitting the command into tokens and determining the appropriate execution path.
- The execute function forks a child process to execute the command, and the parent process waits for the child to complete.
### helpers.c
- The split function divides a command into an array of tokens.
- The pre_execute function prepares the command for execution.
- The execute function handles the actual execution of the command.
- The free_arr function frees memory allocated for an array of strings.
- The print_env function prints the environment variables.
### path.c
- The get_path function retrieves the full path of a command by searching through the directories listed in the PATH environment variable.
## Building and Running
To compile the simple shell, use the following commands:
```
$ gcc *.c -o simple_shell
```
To run the shell:
```
$ ./simple_shell
```
or
```
echo "your_command" | ./simple_shell
```
and finally
```
cat your_commands_file | ./simple_shell
```
## Usage
Once the shell is running, you can enter commands at the prompt. The shell supports basic commands, built-in commands (exit and env), and environment variable handling.
## Notes
- This simple shell project is designed for educational purposes and may not cover all edge cases or advanced features found in professional shells.
- Feel free to explore, modify, and enhance the code to better suit your needs.
**Note** Please ensure you have the necessary permissions to execute the compiled shell.
Happy coding!
## Authors
### Isgenderli Tuncay
### Ravan Asadov