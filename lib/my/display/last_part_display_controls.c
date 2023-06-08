/*
** EPITECH PROJECT, 2023
** last_part_display_controls
** File description:
** last_part_display_controls
*/

#include "my.h"

void display_left_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(controls.pannel);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 370;
    pos.y += 275;
    sfText_setPosition(controls.left_key, pos);
    sfText_setScale(controls.left_key, scale);
    sfText_setFont(controls.left_key, font);
    sfRenderWindow_drawText(window, controls.left_key, NULL);
}

void display_inv_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(controls.pannel);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 340;
    pos.y += 425;
    sfText_setPosition(controls.inv_key, pos);
    sfText_setScale(controls.inv_key, scale);
    sfText_setFont(controls.inv_key, font);
    sfRenderWindow_drawText(window, controls.inv_key, NULL);
}

void display_spacebar_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(controls.pannel);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 305;
    pos.y += 450;
    sfText_setPosition(controls.spacebar_key, pos);
    sfText_setScale(controls.spacebar_key, scale);
    sfText_setFont(controls.spacebar_key, font);
    sfRenderWindow_drawText(window, controls.spacebar_key, NULL);
}
