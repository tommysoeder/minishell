*This project has been created as part of the 42 curriculum by aialonso, tomamart.*

# 🐚 Minishell — As beautiful as a shell

## Description

Minishell is a project from the 42 curriculum that consists of building a functional Unix shell from scratch in C, inspired by Bash.

The goal is to understand how a shell works internally: how it reads input, parses commands, manages processes, handles file descriptors, and interacts with the operating system. It is one of the most complete projects in the 42 curriculum, covering process management (`fork`, `execve`, `waitpid`), inter-process communication (`pipe`), signal handling, I/O redirections, and environment variable expansion.

**Key features:**
- Interactive prompt with command history
- Command execution via `PATH`, relative, or absolute paths
- Input/output redirections: `<`, `>`, `<<`, `>>`
- Pipes (`|`) to chain commands
- Environment variable expansion (`$VAR`, `$?`)
- Signal handling: `ctrl-C`, `ctrl-D`, `ctrl-\`
- Single (`'`) and double (`"`) quote handling
- Built-in commands: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`

---

## Instructions

### Requirements

- GCC compiler
- GNU Make
- `readline` library

On Debian/Ubuntu:
```bash
sudo apt install libreadline-dev
```

### Compilation

```bash
make
```

This will produce the `minishell` executable.

To clean object files:
```bash
make clean
```

To clean everything including the binary:
```bash
make fclean
```

To recompile from scratch:
```bash
make re
```

### Execution

```bash
./minishell
```

Once running, you can type commands just like in Bash:

```bash
minishell$ echo "Hello, World!"
minishell$ ls -la | grep src
minishell$ cat file.txt >> output.txt
minishell$ export MY_VAR=42
minishell$ echo $MY_VAR
minishell$ exit
```

---

## Resources

### Documentation & References

- [GNU Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html) — The main reference for expected shell behaviour.
- [Linux man pages: fork(2), execve(2), pipe(2), signal(7)](https://man7.org/linux/man-pages/) — Essential system calls used throughout the project.
- [readline library documentation](https://tiswww.case.edu/php/chet/readline/rltop.html) — Used for the interactive prompt and history.
- [Writing Your Own Shell — Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/) — A classic tutorial to understand the core concepts.
- [The GNU C Library Reference Manual](https://www.gnu.org/software/libc/manual/) — Reference for standard C library functions.

### AI Usage

AI tools (Claude) were used as a **learning and debugging aid** throughout this project, never as a code generator. Specifically:

- **Concept clarification**: understanding how signals interact with forked processes, how `dup2` works with file descriptors, and how `heredoc` (`<<`) should behave.
- **Debugging guidance**: asking questions about specific bugs (e.g., signal inheritance in child processes, `$?` expansion edge cases) to understand *what* was wrong, not to get a fix.
- **Memory management review**: discussing strategies to avoid leaks, particularly around `readline` and the parser's token list.

All code was written, understood, and is fully explainable by the project authors.
