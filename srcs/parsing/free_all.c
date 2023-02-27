#include "../../headers/cub3d.h"

void    free_strings(t_file *file)
{
    if (file->textures.north != NULL)
        free(file->textures.north);
    if (file->textures.south != NULL)
        free(file->textures.south);
    if (file->textures.east != NULL)
        free(file->textures.east);
    if (file->textures.west != NULL)
        free(file->textures.west);
    return ;
}

void    free_all(t_data *data)
{
    free_strings(&data->file);
    free_tab(data->file.map, data->file.y);
    return ;
}

void    free_alll(t_file *file)
{
    free_strings(file);
    free_tab(file->map, file->y);
    return ;
}