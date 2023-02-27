/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <ojauregu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:18:56 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/26 09:17:22 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define BAD_NB_ARG "bad nb of arguments"
# define EMPTY_ARG_FILE "you have to give an argument"
# define SECRET_FILE "this is a secret file"
# define BAD_NAME_FILE "this is a bad file name"
# define BAD_PATH_FILE "the path is not valid"
# define PATH_IS_DIR "this is a directory"
# define MLX_CONNECTION "the connection between with the display has not been established"
# define WIN_CONNECTION "the window could not be created"
# define MISSING_TEXTURES "one or more textures are missing from the file.cub"
# define DOUBLE_SAME_PATH "tu as mis deux fois le meme path spice di connasse"
# define MALLOC_FAILED "failed to allocate memory"
# define NO_PB "something went wrong with NO path"
# define SO_PB "something went wrong with SO path"
# define WE_PB "something went wrong with WE path"
# define EA_PB "something went wrong with EA path"
# define ELSE_MAP "something went wrong with the map"
# define RET_CEI "something went wrong with ceiling description"
# define RET_FLO "something went wrong with floor description"
# define CEI_COL "ceiling colors must start with C and follow full RGB scale 0 - 255"
# define FLO_COL "floor colors must start with F and follow full RGB scale 0 - 255"
# define FILE_ERR "stopped checking the file at line "



# define UNPROTECTED "unprotected map, some walls are not closed"
# define NO_MAP "where is the map??"
# define NL_IN_MAP "some new line seeems to be on the way of my map"
# define TOO_MUCH_POS "you must put only one starting position"
# define WRONG_CHAR_IN_MAP " is not a receivable character, use -01 NSEW-"
# define READ "something went wrong while reading the file"

#endif