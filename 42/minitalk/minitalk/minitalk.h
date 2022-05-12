/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:42:09 by hejang            #+#    #+#             */
/*   Updated: 2022/05/12 10:45:05 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<unistd.h>
# include<signal.h>
# include<stdio.h>

void	handler(int signo);
void	send_char(int pid, char c, int i);
void	send_bit(int pid, int bit);

#endif
