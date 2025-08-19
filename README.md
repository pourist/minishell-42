# Minishell

A lightweight UNIX shell written in C, reproducing essential features of **bash**.
It implements a full **read–parse–execute loop**, managing processes, signals, pipes, and redirections, while providing builtins and environment variable handling.

---

## 🛠 Architecture

The project is structured into clear stages:

### 1. **Lexing (`lexer.c`)**

* Validates syntax (redirects, unmatched quotes, dangling pipes).
* Splits user input into *pipeline segments* (`cmd1 | cmd2 …`).
* Tokenizes each command into arguments while preserving/stripping quotes.
* Inserts spaces around redirection operators to simplify parsing.

### 2. **Parsing (`parser.c`)**

* Performs **expansions**:

  * Environment variables (`$VAR`, `$?`).
  * Tilde (`~`) → `$HOME` (standalone only).
* Builds `t_operation`:

  * `command` → argv array.
  * `redir` → linked list of input/output/heredoc redirections.
* Prepares heredocs (`<<`) before execution.

### 3. **Execution (`executor.c`, `pipe.c`, `handle_red.c`)**

* **Single command**:

  * Builtins executed in parent when possible (`cd`, `export`, …).
  * External commands fork + `execve`.
* **Pipelines**:

  * Each stage forked with proper fd setup via `dup2`.
  * Parent collects exit status of the last command.
* **Redirections**:

  * `<`, `>`, `>>`, and `<<` handled per-command.
  * Ambiguous cases detected (e.g., `$VAR` as filename).
* **PATH resolution**:

  * `/absolute`, `./relative`, and PATH lookup with caching.

### 4. **Signals (`signals.c`)**

* Parent shell:

  * `Ctrl-C` prints new prompt, `Ctrl-\` ignored.
* Children: default handling restored.
* Heredoc mode: `Ctrl-C` aborts heredoc input by closing stdin.

### 5. **Environment management**

* Stored as a linked list (`t_env`).
* Supports `export`, `unset`, and dynamic updates to `PWD`/`OLDPWD`.
* Expanded during parsing via `ft_getenv`.

---

## Features

* Interactive prompt with `readline` and history.
* Builtins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.
* Pipelines (`|`) with proper fd chaining.
* Redirections: `<`, `>`, `>>`, `<<` (heredoc).
* Env variable expansion + `$?`.
* Exit codes: `126` (exec error), `127` (command not found), `130` (SIGINT), etc.
* Memory/FD cleanup (`free_all`, `reset_stds`) to avoid leaks.

---

## Limitations

* No job control or background execution (`&`).
* No subshells or command grouping (`()` or `{}`).
* Heredoc does not expand variables.
* Tilde expansion limited to standalone `~`.

---

## Build & Run

```bash
make
./minishell
```

Examples:

```bash
$ echo "hello" | grep h
$ ls -l > out.txt
$ cat << EOF
line1
line2
EOF
```


