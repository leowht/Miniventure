/*
** EPITECH PROJECT, 2023
** get_pos_player
** File description:
** get_pos_player
*/

#include "my.h"

all_t get_pos_player(all_t all)
{
    sfVector2f new_pos = sfSprite_getPosition(all.play.player);
    FILE *fd = fopen("assets/pos/player_pos.txt", "w+");
    char *x_pos = my_int_to_str(new_pos.x);
    char *y_pos = my_int_to_str(new_pos.y);

    if (fd == NULL) {
        write(1, "/!\\MISSING FILE : assets/pos/player_pos.txt\n", 45);
        all.status = 1;
        return all;
    }
    fwrite(x_pos, 1, my_strlen(x_pos), fd);
    fwrite(" ", 1, 1, fd);
    fwrite(y_pos, 1, my_strlen(y_pos), fd);
    fclose(fd);
    free(x_pos);
    free(y_pos);
    return all;
}
