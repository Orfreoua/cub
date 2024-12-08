/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:23:47 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 22:23:48 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "headers.h"

long	current_time(long time_start)
{
	return (ft_time() - time_start);
}

long	ft_time(void)
{
	struct timeval	tv;
	long			ret;

	gettimeofday(&tv, (void *)0);
	ret = tv.tv_sec * 1000;
	ret += tv.tv_usec / 1000;
	return (ret);
}
