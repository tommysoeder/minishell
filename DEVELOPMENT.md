# 🛠️ Minishell — Plan de desarrollo

> Guía de desarrollo en pareja · desde cero · C · Norminette · 42 School

---

## 👥 División de trabajo

| | Dev A | Dev B |
|---|---|---|
| **Responsabilidad principal** | Lexer, expansión de variables, ejecución | Parser AST, builtins, entorno |
| **Compartido** | Configuración, señales, memoria, evaluación |

---

## 📊 Progreso general

| Fase | Responsable | Estado |
|------|-------------|--------|
| 0. Configuración inicial | Juntos | `[x]` |
| 1. Lexer y tokenización | Dev A | `[x]` |
| 2. Parsing y árbol AST | Dev B | `[ ]` |
| 3. Expansión de variables | Dev A | `[x]` |
| 4. Builtins | Dev B | `[x]` |
| 5. Ejecución y procesos | Dev A | `[x]` |
| 6. Señales | Juntos | `[x]` |
| 7. Gestión de memoria | Juntos | `[x]` |
| 8. Pulido y evaluación | Juntos | `[ ]` |
| 9. Bonus (opcional) | Pareja | `[ ]` |

---

## Fase 0 — Configuración inicial
> ⏱️ 1-2 días · Juntos

- [x] Leer el subject completo entre los dos y resolver dudas
- [x] Definir la arquitectura: carpetas `src/`, `includes/`, `libft/`
- [x] Configurar el Makefile con reglas `all`, `clean`, `fclean`, `re` *(Dev A)*
- [x] Integrar libft propia (o confirmar funciones permitidas) *(Dev B)*
- [x] Inicializar el repo de GitHub y definir ramas de trabajo
- [x] Acordar convenciones de naming y estilo antes de empezar

---

## Fase 1 — Lexer y tokenización
> ⏱️ 3-4 días · Dev A

- [x] Definir los tipos de token: `WORD`, `PIPE`, `REDIR`, `HEREDOC`, etc.
- [x] Implementar el lexer que lee la línea y genera una lista de tokens
- [x] Manejar comillas simples: preservar contenido literal
- [x] Manejar comillas dobles: expansión de `$VAR` y `$?`
- [x] Detectar y reportar errores: comillas sin cerrar, pipes vacíos
- [x] Tests básicos del lexer con casos límite

---

## Fase 2 — Parsing y árbol AST
> ⏱️ 4-5 días · Dev B

- [x] Definir la estructura del árbol: nodo comando, pipe, redirección
- [x] Implementar el parser que convierte tokens en árbol AST
- [x] Parsear comandos simples con argumentos
- [x] Parsear pipes múltiples correctamente
- [x] Parsear redirecciones `>`, `>>`, `<`, `<<` y asociarlas al nodo correcto
- [ ] Implementar heredoc: leer stdin hasta delimitador
- [x] Función para liberar el árbol AST completamente (sin leaks)

---

## Fase 3 — Expansión de variables
> ⏱️ 2-3 días · Dev A

- [x] Implementar la expansión de `$VAR` buscando en el entorno
- [x] Expansión de `$?` con el exit status del último proceso
- [x] Respetar que dentro de comillas simples no se expande nada
- [x] Manejar variables no definidas como cadena vacía

---

## Fase 4 — Builtins
> ⏱️ 3-4 días · Dev B

- [x] Implementar `echo` con soporte de `-n`
- [ ] Implementar `cd` con rutas relativas, absolutas y `~`
- [ ] Actualizar `$PWD` y `$OLDPWD` en cada `cd`
- [x] Implementar `pwd`
- [ ] Implementar `export`: listar, añadir y actualizar variables
- [ ] Implementar `unset`: eliminar variables del entorno
- [x] Implementar `env`: imprimir entorno actual
- [x] Implementar `exit` con código numérico

---

## Fase 5 — Ejecución y procesos
> ⏱️ 4-5 días · Dev A

- [x] Implementar la búsqueda de binarios en `$PATH`
- [x] `fork` + `execve` para comandos externos
- [x] Gestión de pipes con fork por cada comando
- [x] Redirigir stdin/stdout antes de `execve`
- [x] Cerrar todos los fd de pipes en padre e hijo
- [x] `waitpid` de todos los hijos y capturar exit status
- [x] Distinguir entre builtin (ejecutar en padre) y externo (fork)
- [x] Retornar exit `127` (not found) y `126` (sin permiso)

---

## Fase 6 — Señales
> ⏱️ 2 días · Juntos

- [x] Configurar `SIGINT` (Ctrl+C) en prompt: nueva línea + nuevo prompt
- [x] Ignorar `SIGQUIT` (Ctrl+\\) en el proceso shell principal
- [x] Manejar Ctrl+D (EOF): salir limpiamente
- [x] Restaurar comportamiento por defecto de señales en procesos hijo
- [ ] Verificar exit status `130` (SIGINT) y `131` (SIGQUIT)

---

## Fase 7 — Gestión de memoria
> ⏱️ 2-3 días · Juntos

- [x] Liberar tokens tras cada comando procesado
- [x] Liberar el árbol AST tras cada ejecución
- [x] Llamar a `rl_clear_history` antes de salir *(Dev A)*
- [ ] Liberar la copia del entorno (`envp`) al salir *(Dev B)*
- [ ] Pasar `valgrind --leak-check=full` sin errores definitivos
- [ ] Pasar `valgrind --track-fds=yes`: sin fd sin cerrar

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./minishell
```

---

## Fase 8 — Pulido y evaluación
> ⏱️ 2-3 días · Juntos

- [ ] Pasar norminette en todos los archivos sin errores
- [ ] Probar todos los casos del subject uno a uno
- [ ] Comparar comportamiento con bash en los casos límite
- [ ] Revisar la [checklist de revisión de código](./README.md)
- [ ] Preparar defensa: cada uno entiende el código del otro

```bash
norminette src/ includes/
```

---

## Fase 9 — Bonus (opcional)
> ⏱️ 3-4 días extra · Pareja

- [ ] Implementar `&&` y `||` con prioridad correcta *(Juntos)*
- [ ] Implementar subshell con paréntesis `( cmd )` *(Dev A)*
- [ ] Implementar wildcards `*` en directorio actual *(Dev B)*

---

## 🛠️ Comandos de referencia

```bash
# Compilar
make

# Norminette
norminette src/ includes/

# Leaks y fd
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./minishell

# Comparar con bash
echo "prueba" | bash
echo "prueba" | ./minishell
```

---

## 📚 Recursos útiles

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [man 3 readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [Writing a Shell in C — Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [42 minishell subject](https://cdn.intra.42.fr/pdf/pdf/96832/en.subject.pdf)

---

<p align="center">
  <sub>42 School · Minishell · <a href="./README.md">Ver checklist de revisión</a></sub>
</p>
