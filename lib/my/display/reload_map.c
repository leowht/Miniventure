/*
** EPITECH PROJECT, 2023
** reload_map
** File description:
** reload_map
*/

#include "my.h"

void reload_map(all_t all)
{
    if (all.scene.is_lost)
        sfRenderWindow_clear(all.scene.window, sfColor_fromRGB(229,111,75));
    else
        sfRenderWindow_clear(all.scene.window, sfColor_fromRGB(92,105,159));
    sfRenderWindow_drawSprite(all.scene.window, all.scene.back, NULL);
    sfRenderWindow_drawSprite(all.scene.window, all.play.player, NULL);
    if (!all.scene.is_lost && !all.scene.is_won)
        display_mobs(all, all.mobs);
}
