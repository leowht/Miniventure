/*
** EPITECH PROJECT, 2023
** display_each_controls
** File description:
** display_each_controls
*/

#include "my.h"

void display_exit_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(controls.pannel);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 350;
    pos.y += 500;
    sfText_setPosition(controls.exit_key, pos);
    sfText_setScale(controls.exit_key, scale);
    sfText_setFont(controls.exit_key, font);
    sfRenderWindow_drawText(window, controls.exit_key, NULL);
}

void display_c_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(controls.pannel);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 320;
    pos.y += 475;
    sfText_setPosition(controls.control_key, pos);
    sfText_setScale(controls.control_key, scale);
    sfText_setFont(controls.control_key, font);
    sfRenderWindow_drawText(window, controls.control_key, NULL);
}

void display_title_control(controls_pan_t controls, sfRenderWindow *window,
sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(controls.pannel);
    sfVector2f scale = {1.0, 1.0};

    pos.x += 320;
    pos.y += 135;
    sfText_setPosition(controls.title, pos);
    sfText_setScale(controls.title, scale);
    sfText_setFont(controls.title, font);
    sfRenderWindow_drawText(window, controls.title, NULL);
}

void display_up_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(controls.pannel);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 483;
    pos.y += 215;
    sfText_setPosition(controls.up_key, pos);
    sfText_setScale(controls.up_key, scale);
    sfText_setFont(controls.up_key, font);
    sfRenderWindow_drawText(window, controls.up_key, NULL);
}

void display_down_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(controls.pannel);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 465;
    pos.y += 300;
    sfText_setPosition(controls.down_key, pos);
    sfText_setScale(controls.down_key, scale);
    sfText_setFont(controls.down_key, font);
    sfRenderWindow_drawText(window, controls.down_key, NULL);
}
