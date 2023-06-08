/*
** EPITECH PROJECT, 2023
** save_stat
** File description:
** save_stat
*/

#include "my.h"

void destroy_stat_txt(player_stat_t *player_stat)
{
    sfText_destroy(player_stat->att_t);
    sfText_destroy(player_stat->def_t);
    sfText_destroy(player_stat->pv_t);
    sfText_destroy(player_stat->lck_t);
    sfText_destroy(player_stat->xp_t);
    sfText_destroy(player_stat->lvl_t);
}

void fill_save_stat(FILE *fd, player_stat_t *play_stat, char *buf)
{
    fwrite("PV ", 1, my_strlen("PV "), fd);
    buf = my_int_to_str(play_stat->pv);
    fwrite(buf, 1,my_strlen(buf), fd);
    fwrite("\nATT ", 1, my_strlen("\nATT "), fd);
    buf = my_int_to_str(play_stat->att);
    fwrite(buf, 1,my_strlen(buf), fd);
    fwrite("\nDEF ", 1, my_strlen("\nDEF "), fd);
    buf = my_int_to_str(play_stat->def);
    fwrite(buf, 1,my_strlen(buf), fd);
    fwrite("\nLCK ", 1, my_strlen("\nLCK "), fd);
    buf = my_int_to_str(play_stat->lck);
    fwrite(buf, 1,my_strlen(buf), fd);
    fwrite("\nXP ", 1, my_strlen("\nXP "), fd);
    buf = my_int_to_str(play_stat->xp);
    fwrite(buf, 1,my_strlen(buf), fd);
    fwrite("\nLVL ", 1, my_strlen("\nLVL "), fd);
    buf = my_int_to_str(play_stat->lvl);
    fwrite(buf, 1,my_strlen(buf), fd);
    fwrite("\n", 1, my_strlen("\n"), fd);
}

void save_stat(player_stat_t *play_stat)
{
    FILE *fd = fopen("assets/stat/cypher_stat.txt", "w+");
    char *buf = NULL;

    fill_save_stat(fd, play_stat, buf);
    fclose(fd);
}
