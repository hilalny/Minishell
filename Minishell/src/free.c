/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaman <ayaman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:31:33 by ayaman            #+#    #+#             */
/*   Updated: 2023/05/10 23:48:16 by ayaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	free_core(void)
{
	free_metachars();
	free_envtable();
	rl_clear_history();
}

void	free_for_loop(void)
{
	if (g_core.cmd)
	{
		free(g_core.cmd);
		g_core.cmd = NULL;
	}
	if (g_core.lex_table)
		free_lexer();
	if (g_core.cmd_table)
		free_parser();
	close_heradoc_file();
}
