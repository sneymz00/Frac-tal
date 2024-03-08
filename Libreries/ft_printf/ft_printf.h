/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:59:06 by camurill          #+#    #+#             */
/*   Updated: 2024/02/21 12:30:25 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//includes
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

//Funtions printf

int	ft_printf(const char *str, ...);
int	ft_characther(int c);
int	ft_string(char *str);
int	ft_number(int n);
int	ft_unsigned_number(unsigned int n);
int	ft_hexadecimal(unsigned int n, const char places);
int	ft_voidpointer(unsigned long n);

#endif