/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:35:01 by adesvall          #+#    #+#             */
/*   Updated: 2021/02/06 19:14:06 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t		ft_strlen(char const *str);
char		*ft_strcpy(char *dst, char const *src);
int			ft_strcmp(char const *dst, char const *src);
char		*ft_strdup(char const *str);

#endif