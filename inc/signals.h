/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:20:10 by aialonso          #+#    #+#             */
/*   Updated: 2026/03/17 15:29:09 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <unistd.h>
# include <signal.h>

extern volatile sig_atomic_t	g_signal;

void	sigint_interactive_handler(int sig);//handler para SIGINT en interactivo
void	signals_interactive(void); // configuración de señales para readline
void	signals_parent_exec(void);//comportamiento del padre durante la ejecuión
void	signals_child_exec(void); // comportamiento del hijo antes de execve

#endif