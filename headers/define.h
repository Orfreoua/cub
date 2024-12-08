/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:44:27 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/28 23:44:28 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "headers.h"

# define KO 1 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define ERROR -1
# define ERROR_BIS -4
# define MAP_ERROR -1
# define EXIT_FAILLURE -1
# define OK 0
# define RED "\x1B[31m"
# define BLU "\x1B[34m"
# define NRM "\x1B[0m"

# define R_WIDTH 			640
# define R_HEIGHT 			480

# define FOV 60
# define PRECISION 128
# define WALL_GAP 0.2
# define ROT_SP 1
# define RUN_SP 10
# define SIDE_SP 50

# define ORANGE_PEEL 0xFFA500
# define WHEAT_BEIGE 0xF5DEB3
# define BABY_BLUE 0x87CEEB
# define LAVENDER_MIST 0xE6E6FA

#endif
