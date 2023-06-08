/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** settings_event.c
*/

#include "my.h"

static all_t is_pressed(all_t all)
{
    if (all.scene.event.type == sfEvtKeyPressed && KP(sfKeySpace)
    && all.menu.current_pos == 0 && all.menu.settings.is_return != 1) {
        all.scene.win_size.x += 10;
        all.scene.win_size.y += 10;
        sfRenderWindow_setSize (all.scene.window, all.scene.win_size);
    } if (all.scene.event.type == sfEvtKeyPressed && KP(sfKeySpace)
    && all.menu.current_pos == 1 && all.menu.settings.is_return != 1) {
        all.scene.win_size.x -= 10;
        all.scene.win_size.y -= 10;
        sfRenderWindow_setSize (all.scene.window, all.scene.win_size);
    } if (all.scene.event.type == sfEvtKeyPressed
    && KP(sfKeySpace) && all.menu.settings.is_return == 1) {
        all.menu.settings.is_open = false;
    } return all;
}

static all_t is_over(all_t all)
{
    if (all.menu.current_pos == 0 && all.menu.settings.is_return != 1)
        sfSprite_setTexture(all.menu.settings.b_plus.button,
        all.menu.settings.b_hover, sfTrue);
    else
        sfSprite_setTexture(all.menu.settings.b_plus.button,
        all.menu.settings.b_none, sfTrue);
    if (all.menu.current_pos == 1 && all.menu.settings.is_return != 1)
        sfSprite_setTexture(all.menu.settings.b_minus.button,
        all.menu.settings.b_hover, sfTrue);
    else
        sfSprite_setTexture(all.menu.settings.b_minus.button,
        all.menu.settings.b_none, sfTrue);
    if (all.menu.settings.is_return == 1 && all.menu.settings.is_return == 1)
        sfSprite_setTexture(all.menu.settings.b_return.button,
        all.menu.settings.b_hover_rect, sfTrue);
    else
        sfSprite_setTexture(all.menu.settings.b_return.button,
        all.menu.settings.b_none_rect, sfTrue);
    return all;
}

all_t settings_events(all_t all)
{
    if (all.scene.event.type == sfEvtKeyPressed
    && KP(sfKeyUp) && all.menu.settings.is_return > 0) {
        all.menu.settings.is_return -= 1;
    } if (all.scene.event.type == sfEvtKeyPressed
    && KP(sfKeyDown) && all.menu.settings.is_return < 1) {
        all.menu.settings.is_return += 1;
    } if (all.scene.event.type == sfEvtKeyPressed
    && KP(sfKeyLeft) && all.menu.current_pos > 0) {
        all.menu.current_pos -= 1;
    } if (all.scene.event.type == sfEvtKeyPressed
    && KP(sfKeyRight) && all.menu.current_pos < 1) {
        all.menu.current_pos += 1;
    } all = is_over(all);
    sfRenderWindow_clear(all.scene.window, sfColor_fromRGB(24,20,37));
    all = is_pressed(all);
    return all;
}
