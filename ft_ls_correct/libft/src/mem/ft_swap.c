/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:19:15 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/04/15 20:10:49 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(void *a, void *b, size_t s)
{
	void	*tmp;

	tmp = malloc(s);
	ft_memcpy(tmp, a, s);
	ft_memcpy(a, b, s);
	ft_memcpy(b, tmp, s);
	free(tmp);
}
