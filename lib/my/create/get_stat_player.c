/*
** EPITECH PROJECT, 2023
** get_stat_player
** File description:
** get_stat_player
*/

#include "my.h"

void fill_the_stat(char *stat, size_t *stat_name)
{
    int i = 0;
    int c = 0;
    char *num;

    for (; stat[i] > '9' || stat[i] < '0'; i++);
    num = malloc(sizeof(char) * (i + 1));
    for (; stat[i] != '\0'; i++) {
        num[c] = stat[i];
        c++;
    }
    num[c] = '\0';
    (*stat_name) = my_getnbr(num);
}

void fill_stat(char **stat_f, player_stat_t *play_stat)
{
    int i = 0;

    for (; stat_f[i] != NULL; i++) {
        if (my_strncmp(stat_f[i], "PV", 2) == 0)
            fill_the_stat(stat_f[i], &play_stat->pv);
        if (my_strncmp(stat_f[i], "ATT", 3) == 0)
            fill_the_stat(stat_f[i], &play_stat->att);
        if (my_strncmp(stat_f[i], "DEF", 3) == 0)
            fill_the_stat(stat_f[i], &play_stat->def);
        if (my_strncmp(stat_f[i], "LCK", 3) == 0)
            fill_the_stat(stat_f[i], &play_stat->lck);
        if (my_strncmp(stat_f[i], "XP", 2) == 0)
            fill_the_stat(stat_f[i], &play_stat->xp);
        if (my_strncmp(stat_f[i], "LVL", 3) == 0)
            fill_the_stat(stat_f[i], &play_stat->lvl);
    }
}

player_stat_t fill_buf(player_stat_t stat, int fd, struct stat num)
{
    char *buf;
    char **stat_f;

    buf = malloc(sizeof(char) * num.st_size);
    read(fd, buf, num.st_size);
    stat_f = my_str_to_word_array(buf, '\n');
    fill_stat(stat_f, &stat);
    free(buf);
    return stat;
}

player_stat_t get_stat(player_stat_t play_stat, char *path)
{
    struct stat num;
    int fd = 0;

    play_stat.file_path = path;
    fd = open(play_stat.file_path, O_RDONLY);
    stat(play_stat.file_path, &num);
    play_stat = fill_buf(play_stat, fd, num);
    close(fd);
    play_stat.max_pv = play_stat.pv;
    return play_stat;
}
