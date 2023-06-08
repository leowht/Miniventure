/*
** EPITECH PROJECT, 2023
** update_stat
** File description:
** update_stat
*/

#include "my.h"

void up_stat_rand(int stat_up, player_stat_t *player)
{
    if (stat_up == 0)
        player->max_pv += 1;
    if (stat_up == 1)
        player->att += 1;
    if (stat_up == 2)
        player->def += 1;
    if (stat_up == 3)
        player->lck += 1;
    player->pv = player->max_pv;
}

void update_stat(player_stat_t *player_stat)
{
    int stat_up = 0;

    player_stat->pv = player_stat->max_pv;
    player_stat->xp += 3;
    if (player_stat->xp >= 10) {
        player_stat->xp -= 10;
        player_stat->lvl += 1;
        srand(time(0));
        stat_up = rand() % 4;
        up_stat_rand(stat_up, player_stat);
    }
}
