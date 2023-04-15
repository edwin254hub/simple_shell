0x16. C - Simple Shell

Requirements:

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)
* Write a README with the description of your project
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

Output:

Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

Compilation:
Below is the way the shell will be compiled
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Tasks:

task 0: Write a beautiful code that passes the Betty checks

task 1: Write a UNIX command line interpreter

task 2: Simple shell 0.1 +
 * handle command lines with arguments

task 3: Simple shell 0.2 +
 * Handle the PATH
 * fork must not be called if the command  doesn't exist

task 4: Simple shell 0.3 +
 * Implement the exit built-in, that exits the shell
 * Usage: exit
 * You don’t have to handle any argument to the built-in exit

task 5: Simple shell 0.4 +
 * Implement the env built-in, that prints the current environment

task 6: Simple shell 0.1 +
 * Write your own getline function
 * Use a buffer to read many chars at once and call the least possible the read system call
 * You will need to use static variables
 * You are not allowed to use getline

task 7: Simple shell 0.2 +
 * You are not allowed to use strtok

task 8: Simple shell 0.4 +
 * handle arguments for the built-in exit
 * Usage: exit status, where status is an integer used to exit the shell

task 9: Simple shell 1.0 +

Implement the setenv and unsetenv builtin commands
 * setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
 * unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure

task 10: Simple shell 1.0 +

Implement the builtin command cd:
 * Changes the current directory of the process.
 * Command syntax: cd [DIRECTORY]
 * If no argument is given to cd the command must be interpreted like cd $HOME
 * You have to handle the command cd -
 * You have to update the environment variable PWD when you change directory
man chdir, man getcwd

task 11: Simple shell 1.0 +
 * Handle the commands separator ;

task 12: Simple shell 1.0 +
 * Handle the && and || shell logical operators

task 13: Simple shell 1.0 +

Implement the alias builtin command
 * Usage: alias [name[='value'] ...]
 * alias: Prints a list of all aliases, one per line, in the form name='value'
 * alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
 * alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value

task 14: Simple shell 1.0 +
 * Handle variables replacement
 * Handle the $? variable
 * Handle the $$ variable

task 15: Simple shell 1.0 +
 * Handle comments (#)

task 16: Simple shell 1.0 +
Usage: simple_shell [filename]
 * Your shell can take a file as a command line argument
 * The file contains all the commands that your shell should run before exiting
 * The file should contain one command per line
 * In this mode, the shell should not print a prompt and should not read from stdin
