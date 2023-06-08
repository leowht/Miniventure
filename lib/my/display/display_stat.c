/*
** EPITECH PROJECT, 2023
** display_stat
** File description:
** display att def lck xp lvl
*/

#include "my.h"

void display_lck(sfText *def_t, sfRenderWindow *window,
sfSprite *inventory, sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(inventory);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 125;
    pos.y += 111;
    sfText_setPosition(def_t, pos);
    sfText_setScale(def_t, scale);
    sfText_setFont(def_t, font);
    sfRenderWindow_drawText(window, def_t, NULL);
}

void display_def(sfText *def_t, sfRenderWindow *window,
sfSprite *inventory, sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(inventory);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 125;
    pos.y += 86;
    sfText_setPosition(def_t, pos);
    sfText_setScale(def_t, scale);
    sfText_setFont(def_t, font);
    sfRenderWindow_drawText(window, def_t, NULL);
}

void display_att(sfText *att_t, sfRenderWindow *window,
sfSprite *inventory, sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(inventory);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 125;
    pos.y += 63;
    sfText_setPosition(att_t, pos);
    sfText_setScale(att_t, scale);
    sfText_setFont(att_t, font);
    sfRenderWindow_drawText(window, att_t, NULL);
}
