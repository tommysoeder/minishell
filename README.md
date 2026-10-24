# Minishell

**A Unix shell written in C, developed collaboratively at 42 Madrid.**

*This project has been created as part of the 42 curriculum by aialonso, tomamart.*

Minishell explores what happens between typing a command and seeing its result: reading input, parsing tokens, expanding variables, launching processes, connecting pipes, and handling signals. Inspired by Bash, it implements a focused set of shell features as a systems programming learning project.

**Core technologies:** C · Unix/Linux · POSIX system calls · GNU Readline · Make

## Features

- Interactive prompt with command history through GNU Readline.
- External command execution using `PATH`, relative paths, or absolute paths.
- External-command pipelines with `|` and input/output redirections: `<`, `>`, `>>`, and heredocs with `<<`.
- Environment variable expansion with `$VAR` and exit status expansion with `$?`.
- Single and double quote handling.
- Built-in commands: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- Signal handling for `Ctrl+C` and `Ctrl+\`, plus end-of-input handling with `Ctrl+D`.

Minishell implements a subset of Bash behaviour for educational use.

## My contributions

This was a two-person project with **aialonso**. My main contributions as **tomamart ([tommysoeder](https://github.com/tommysoeder))** were:

- **Signal handling:** contributing the logic for signal behaviour in the interactive shell and child processes.
- **Environment variable expansion:** implementing variable substitution during command processing.
- **Parsing:** contributing to part of the command parsing logic.
- **Integration and debugging:** helping bring the components together and investigate issues across the shell.

The feature list describes our shared project. The contributions above describe my main areas of work.

## Technical concepts

| Area | Concepts explored |
| --- | --- |
| Processes | Creating child processes with `fork`, executing programs with `execve`, and waiting for them with `waitpid` |
| Pipes and redirections | Connecting commands with `pipe`, redirecting file descriptors with `dup2`, and managing descriptor lifetimes |
| Signals | Handling `SIGINT` and `SIGQUIT` across the interactive shell and child processes |
| Parsing and expansion | Tokenising input, handling quotes, and resolving environment variables and exit status |
| Memory and resources | Managing dynamically allocated command data, environment entries, and cleanup paths in C |
| Collaboration | Integrating separately developed components and debugging their interactions |

## Build and run

### Requirements

- A Linux environment with a C compiler available as `cc` (GCC or Clang).
- GNU Make and Git.
- GNU Readline development headers and library.
- Compiler support and runtime libraries for AddressSanitizer, enabled by the existing Makefile.

On Debian or Ubuntu, install the build dependencies:

```bash
sudo apt update
sudo apt install build-essential git libreadline-dev
```

Clone this repository, build it, and start the shell:

```bash
git clone https://github.com/tommysoeder/minishell.git
cd minishell
make
./minishell
```

The build uses the bundled library in `lib/` and links against GNU Readline. The current Makefile enables `-Wall -Wextra -Werror`, debug symbols (`-g3`), and AddressSanitizer (`-fsanitize=address`).

| Command | Purpose |
| --- | --- |
| `make` | Build the `minishell` executable |
| `make clean` | Remove object files |
| `make fclean` | Remove object files, the bundled library archive, and the executable |
| `make re` | Rebuild from scratch |

## Usage examples

After launching `./minishell`, enter these commands one line at a time:

```bash
pwd
echo "Hello from Minishell"
ls -l | wc -l
export PROJECT=Minishell
echo "$PROJECT"
echo '$PROJECT'
false
echo $?
exit
```

The double-quoted variable is expanded; the single-quoted version stays literal. `false` exits with status `1`, which can then be inspected with `echo $?`.

To try redirections, run the following inside Minishell. These commands create or overwrite `minishell-demo.txt` in the current directory:

```bash
ls -l > minishell-demo.txt
ls -l >> minishell-demo.txt
cat < minishell-demo.txt
```

## Scope and current limitations

- Builtins at the start of a pipeline run through a separate execution path, so those pipelines do not behave like Bash pipelines.
- Pipeline exit status is based on the last child reaped, which may differ from the last command in the pipeline.
- Heredoc input is read literally; variables in its body are not expanded.
- Logical operators (`&&`, `||`), wildcard expansion, subshells, and job control are outside the current implementation.

## What I learned

- How signal handling affects an interactive program and the processes it launches.
- Why quote handling and variable expansion need to be considered together during parsing.
- How process execution, file descriptors, and resource cleanup interact in a shell.
- How to investigate integration bugs and coordinate changes in a shared C codebase.

## Authors and credits

- **tomamart** — [tommysoeder](https://github.com/tommysoeder). Main contributions described above.
- **aialonso** — co-author of this collaborative 42 project.

This repository is a fork of the [original collaboration repository](https://github.com/PAYTheVendetta/minishell). Credit for the project belongs to both authors.

## Resources

- [GNU Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html) — reference for shell behaviour.
- [Linux man pages](https://man7.org/linux/man-pages/) — documentation for system calls such as `fork`, `execve`, and `pipe`, and for signals.
- [GNU Readline documentation](https://tiswww.case.edu/php/chet/readline/rltop.html) — interactive input and history.
- [Writing Your Own Shell — Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/) — introduction to shell implementation.
- [The GNU C Library Reference Manual](https://www.gnu.org/software/libc/manual/) — C library reference.

## AI Usage

AI tools (Claude) were used as a **learning and debugging aid** throughout this project, never as a code generator. Specifically:

- **Concept clarification**: understanding how signals interact with forked processes, how `dup2` works with file descriptors, and how `heredoc` (`<<`) should behave.
- **Debugging guidance**: asking questions about specific bugs (e.g., signal inheritance in child processes, `$?` expansion edge cases) to understand *what* was wrong, not to get a fix.
- **Memory management review**: discussing strategies to avoid leaks, particularly around `readline` and the parser's token list.

All code was written, understood, and is fully explainable by the project authors.
