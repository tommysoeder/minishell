#ifndef SIGNALS_H
# define SIGNALS_H

#include <signal.h>

extern volatile sig_atomic_t    g_signal; // variable global para identificar la señal

void sigint_interactive_handler(int sig); // handler para SIGINT en interactivo
void signals_interactive(void); // configuración de señales para readline
void signals_parent_exec(void); // comportamiento del padre durante la ejecuión
void signals_child_exec(void); // comportamiento del hijo antes de execve

#endif