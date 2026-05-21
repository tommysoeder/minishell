/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:20:10 by aialonso          #+#    #+#             */
/*   Updated: 2026/05/21 13:58:31 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <unistd.h>
# include <signal.h>

extern volatile sig_atomic_t	g_signal;

void	sigint_interactive_handler(int sig);
void	signals_interactive(void);
void	signals_parent_exec(void);
void	signals_child_exec(void);
void	check_child_signal(int status);

#endif