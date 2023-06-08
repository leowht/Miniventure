/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** camera.c
*/

#include "my.h"

void set_view(player_t *player, sfRenderWindow *window)
{
    sfView_setCenter(player->view, sfSprite_getPosition(player->player));
    sfRenderWindow_setView(window, player->view);
}

void create_view(player_t *player, sfRenderWindow *window)
{
    player->view = sfView_create();
    sfView_setCenter(player->view, sfSprite_getPosition(player->player));
    sfView_setSize(player->view, (sfVector2f) {960, 540});
    sfRenderWindow_setView(window, player->view);
}
