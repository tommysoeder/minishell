# 🐚 Minishell — 42 School

> Implementación de un shell en C siguiendo la Norminette de 42.

---

## 📋 Checklist de revisión de código

Usa esta checklist antes de cada evaluación para asegurarte de que nada se escapa.

> 💡 **Descarga la versión imprimible** en [Releases](../../releases) · `minishell_checklist.docx`

---

### 📐 Norminette

- [ ] Todas las funciones tienen máximo 25 líneas
- [ ] Máximo 5 funciones por archivo `.c`
- [ ] Máximo 4 parámetros por función
- [ ] No hay declaraciones de variables fuera del inicio de función
- [ ] No se usan `for`, `do..while`, `switch` ni operadores ternarios
- [ ] Los nombres siguen `snake_case` y convenciones de 42
- [ ] No hay líneas de más de 80 caracteres
- [ ] No hay funciones no autorizadas (solo las del subject) ⚠️ `crash`

---

### `{ }` Parsing y tokenización

- [X] El lexer maneja correctamente comillas simples (sin expansión) ⚠️ `crash`
- [X] El lexer maneja correctamente comillas dobles (con expansión de `$`) ⚠️ `crash`
- [X] Las comillas sin cerrar devuelven error y no crashean ⚠️ `crash`
- [ ] El parsing de pipes `|` es correcto (incluye pipes múltiples) ⚠️ `crash`
- [ ] Las redirecciones `>`, `>>`, `<`, `<<` se parsean correctamente ⚠️ `crash`
- [ ] El heredoc `<<` bloquea la entrada hasta el delimitador ⚠️ `crash`
- [x] Los espacios y tabs entre tokens se ignoran correctamente
- [x] Los comandos vacíos o solo espacios no crashean ⚠️ `crash`
- [x] La expansión de `$?` devuelve el exit status del último comando
- [x] La expansión de `$VAR` funciona dentro de comillas dobles

---

### `$_` Builtins

- [x] `echo` funciona con `-n` y sin argumentos ⚠️ `crash`
- [ ] `cd` acepta rutas relativas, absolutas, `~` y sin argumentos (`HOME`) ⚠️ `crash`
- [ ] `cd` actualiza `$PWD` y `$OLDPWD` correctamente
- [x] `pwd` imprime el directorio actual sin argumentos
- [ ] `export` sin argumentos lista variables en formato `declare -x`
- [ ] `export VAR=valor` añade o actualiza la variable de entorno
- [ ] `unset` elimina variables de entorno y no falla si no existen
- [x] `env` imprime el entorno actual
- [x] `exit` acepta un código numérico y sale con ese código `% 256` ⚠️ `crash`
- [ ] Los builtins en un subshell (dentro de pipe) no afectan el shell padre

---

### `▶` Ejecución y procesos

- [x] Los comandos externos se buscan en `$PATH` correctamente ⚠️ `crash`
- [ ] `execve` recibe `argv` y `envp` correctamente construidos ⚠️ `crash`
- [ ] Cada comando en un pipe se ejecuta en un proceso hijo (`fork`) ⚠️ `crash`
- [x] El proceso padre hace `waitpid` de todos los hijos ⚠️ `crash`
- [ ] El exit status del pipeline es el del último comando
- [ ] Los file descriptors de pipes se cierran en padre e hijo 🪣 `leak`
- [ ] Las redirecciones de entrada/salida se aplican antes de `execve` ⚠️ `crash`
- [ ] Un comando no encontrado devuelve exit `127`
- [ ] Un binario sin permiso de ejecución devuelve exit `126`

---

### `~` Señales

- [ ] `Ctrl+C` (SIGINT) en prompt imprime nueva línea y nuevo prompt ⚠️ `crash`
- [ ] `Ctrl+\` (SIGQUIT) en prompt no hace nada (ignorado) ⚠️ `crash`
- [ ] `Ctrl+D` en prompt cierra el shell limpiamente ⚠️ `crash`
- [ ] `Ctrl+C` durante ejecución de comando interrumpe el hijo, no el shell ⚠️ `crash`
- [ ] `Ctrl+\` durante ejecución genera core dump solo en el hijo
- [ ] El exit status tras SIGINT es `130`, tras SIGQUIT es `131`

---

### `M` Memoria y leaks

- [ ] Todo `malloc` tiene su `free` correspondiente (valgrind limpio) 🪣 `leak`
- [x] `readline` no genera leaks — usar `rl_clear_history` al salir 🪣 `leak`
- [x] El árbol AST / lista de tokens se libera completamente tras cada comando 🪣 `leak`
- [ ] El entorno (`envp` copia) se libera al salir 🪣 `leak`
- [ ] Los file descriptors abiertos se cierran antes de salir 🪣 `leak`
- [ ] No hay double free ni uso después de free ⚠️ `crash` 🪣 `leak`
- [ ] `valgrind --leak-check=full` no muestra errores definitivos 🪣 `leak`

---

### ⭐ Bonus

- [ ] Operadores `&&` y `||` con prioridad correcta ⚠️ `crash`
- [ ] Subshell con paréntesis `( cmd )` ejecuta en proceso hijo
- [ ] Wildcards `*` se expanden correctamente en el directorio actual

---

## 🏷️ Leyenda

| Etiqueta | Significado |
|----------|-------------|
| ⚠️ `crash` | Puede hacer fallar la evaluación directamente |
| 🪣 `leak` | Memory leak detectado por valgrind |
| 📐 `norma` | Violación de la Norminette |
| ⭐ `bonus` | Parte opcional del proyecto |

---

## 🛠️ Comandos útiles

```bash
# Compilar
make

# Comprobar norminette
norminette src/ includes/

# Detectar leaks
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./minishell

# Comprobar file descriptors abiertos
valgrind --track-fds=yes ./minishell
```

---

## 📚 Recursos

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [man readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [Writing a Shell in C — Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/)

---

<p align="center">
  <sub>Hecho con ❤️ para 42 School · <a href="../../releases">Descargar checklist .docx</a></sub>
</p>
