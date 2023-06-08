/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** collision_detector.c
*/

#include "my.h"

int obs_right(player_t *player)
{
    sfVector2f coords = sfSprite_getPosition(player->player);
    sfColor color = sfImage_getPixel(player->map_colliosions,
    ((unsigned int)coords.x + player->offset - 8),
    ((unsigned int)coords.y + player->offset - 14));
    if (color.r == 255 && color.g == 0 && color.b == 0) {
        return 1;
    }
    color = sfImage_getPixel(player->map_colliosions,
    ((unsigned int)coords.x + player->offset - 8),
    ((unsigned int)coords.y + player->offset - 7));
    if (color.r == 255 && color.g == 0 && color.b == 0) {
        return 1;
    }
    return 0;
}

int obs_left(player_t *player)
{
    sfVector2f coords = sfSprite_getPosition(player->player);
    sfColor color = sfImage_getPixel(player->map_colliosions,
    ((unsigned int)coords.x + 8),
    ((unsigned int)coords.y + player->offset - 14));
    if (color.r == 255 && color.g == 0 && color.b == 0) {
        return 1;
    }
    color = sfImage_getPixel(player->map_colliosions,
    ((unsigned int)coords.x + 8),
    ((unsigned int)coords.y + player->offset - 7));
    if (color.r == 255 && color.g == 0 && color.b == 0) {
        return 1;
    }
    return 0;
}

int obs_up(player_t *player)
{
    sfVector2f coords = sfSprite_getPosition(player->player);
    sfColor color = sfImage_getPixel(player->map_colliosions,
    ((unsigned int)coords.x + player->offset - 12),
    ((unsigned int)coords.y + player->offset - 20));
    if (color.r == 255 && color.g == 0 && color.b == 0) {
        return 1;
    }
    color = sfImage_getPixel(player->map_colliosions,
    ((unsigned int)coords.x + 12),
    ((unsigned int)coords.y + player->offset - 20));
    if (color.r == 255 && color.g == 0 && color.b == 0) {
        return 1;
    }
    return 0;
}

int obs_down(player_t *player)
{
    sfVector2f coords = sfSprite_getPosition(player->player);
    sfColor color = sfImage_getPixel(player->map_colliosions,
    ((unsigned int)coords.x + player->offset - 12),
    ((unsigned int)coords.y + player->offset - 3));
    if (color.r == 255 && color.g == 0 && color.b == 0) {
        return 1;
    }
    color = sfImage_getPixel(player->map_colliosions,
    ((unsigned int)coords.x + 12),
    ((unsigned int)coords.y + player->offset - 3));
    if (color.r == 255 && color.g == 0 && color.b == 0) {
        return 1;
    }
    return 0;
}
