/*
** EPITECH PROJECT, 2023
** move
** File description:
** contains movement animation && movement
*/

#include "my.h"

void horizontal_move(player_t *player)
{
    if (KP(sfKeyRight) && obs_right(player) != 1)
        sfSprite_move(player->player, (sfVector2f){2, 0});
    else if (KP(sfKeyLeft) && obs_left(player) != 1)
        sfSprite_move(player->player, (sfVector2f){-2, 0});
    return;
}

void vertical_move(player_t *player)
{
    if (KP(sfKeyUp) && obs_up(player) != 1)
        sfSprite_move(player->player, (sfVector2f){0, -2});
    else if (KP(sfKeyDown) && obs_down(player) != 1)
        sfSprite_move(player->player, (sfVector2f){0, 2});
    return;
}

void move_sprite(player_t *player)
{
    if (KP(sfKeyRight) || KP(sfKeyLeft))
        horizontal_move(player);
    else if (KP(sfKeyUp) || KP(sfKeyDown))
        vertical_move(player);
    return;
}

void move(player_t *player)
{
    if (player->val_max != 256) {
        player->rect.left = 0;
        player->val_max = 256;
        player->rect.top = 64;
    }
    move_sprite(player);
    return;
}
