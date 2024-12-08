/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drago.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:22:41 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 22:26:53 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

// void    move_two(t_data *data)
// {
//     if (data->drago.pos.x < R_WIDTH)
//     {
//         if (data->frame >= 51)
//             data->frame = 0;
//         mlx_put_image_to_window(data->mlx, data->win,
// data->drago.textures_b[data->frame].img, data->drago.pos.x,
// data->drago.pos.y);
//         data->drago.pos.x+=3;
//         data->drago.pos.y--;
//         if (data->frame > 45)
//             data->drago.pos.y--;
//     }
//     else if (data->drago.z >= -200)
//     {
//         if (data->frame >= 47)
//             data->frame = 0;
//         mlx_put_image_to_window(data->mlx, data->win,
// data->drago.textures[data->frame].img, data->drago.z, data->drago.pos.y);
//         data->drago.z-=3;
//         data->drago.pos.y--;
//         if (data->frame > 45)
//             data->drago.pos.y--;
//     }
//     if (data->drago.z <= -200)
//     {
//         data->drago.pos.x = -200;
//         data->drago.z = R_WIDTH;
//     }
// }

// void    move_one(t_data *data)
// {
//     if (data->drago.pos.x < R_WIDTH)
//     {
//         if (data->frame >= 51)
//             data->frame = 0;
//         mlx_put_image_to_window(data->mlx,
// data->win, data->drago.textures_b[data->frame].img,
// data->drago.pos.x, data->drago.pos.y);
//         data->drago.pos.x+=3;
//     }
//     else if (data->drago.z >= -200)
//     {
//         if (data->frame >= 47)
//             data->frame = 0;
//         mlx_put_image_to_window(data->mlx, data->win,
// data->drago.textures[data->frame].img, data->drago.z, data->drago.pos.y);
//         data->drago.z-=3;
//     }
//     if (data->drago.z <= -200)
//     {
//         data->drago.pos.x = -200;
//         data->drago.z = R_WIDTH;
//     }
// }

// void    drago(t_data *data)
// {
//     long elapsed_time = current_time(data->time_start);
//     if (elapsed_time > 25)
//     {
//         data->time_start = ft_time();
//         data->frame++;
//     }
//     if (!data->inactive_time)
//         move_one(data);
//     else
//      move_two(data);
//     sea(data);
//     if (data->drago.pos.y <= -1000)
//     {
//         data->inactive_time = 0;
//         data->drago.pos.y = 30;
//         if ((int)ft_time() % 2)
//             data->drago.pos.x = R_WIDTH;
//         else
//             data->drago.pos.x = -200;
//         data->drago.z = R_WIDTH;
//     }
// }
