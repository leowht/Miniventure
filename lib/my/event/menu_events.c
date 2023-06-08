/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** menu_events.c
*/

#include "my.h"

static all_t is_pressed(all_t all)
{
    if (all.scene.event.type == sfEvtKeyPressed && KP(sfKeySpace)
    && all.menu.current_pos == 0) {
        all.player_stat = get_stat(all.player_stat,
        "assets/stat/base_stat.txt");
        all.menu.is_open = false;
    } if (all.scene.event.type == sfEvtKeyPressed
    && KP(sfKeySpace) && all.menu.current_pos == 3)
        close_window(all.scene.window);
    if (all.scene.event.type == sfEvtKeyPressed && KP(sfKeySpace)
    && all.menu.current_pos == 1) {
        sfSprite_setPosition(all.play.player, get_player_pos());
        all.menu.is_open = false;
    } if (all.scene.event.type == sfEvtKeyPressed && KP(sfKeySpace)
    && all.menu.current_pos == 2) {
        all.menu.settings.is_open = true;
        all = settings_loop(all);
    } return all;
}

static all_t is_over_sec(all_t all)
{
    if (all.menu.current_pos == 2)
        sfSprite_setTexture(all.menu.b_settings.button,
        all.menu.b_hover, sfTrue);
    else
        sfSprite_setTexture(all.menu.b_settings.button,
        all.menu.b_none, sfTrue);
    if (all.menu.current_pos == 3)
        sfSprite_setTexture(all.menu.b_exit.button,
        all.menu.b_hover, sfTrue);
    else
        sfSprite_setTexture(all.menu.b_exit.button,
        all.menu.b_none, sfTrue);
    return all;
}

static all_t is_over(all_t all)
{
    if (all.menu.current_pos == 0)
        sfSprite_setTexture(all.menu.b_start.button,
        all.menu.b_hover, sfTrue);
    else
        sfSprite_setTexture(all.menu.b_start.button,
        all.menu.b_none, sfTrue);
    if (all.menu.current_pos == 1)
        sfSprite_setTexture(all.menu.b_resume.button,
        all.menu.b_hover, sfTrue);
    else
        sfSprite_setTexture(all.menu.b_resume.button,
        all.menu.b_none, sfTrue);
    all = is_over_sec(all);
    return all;
}

all_t menu_events(all_t all)
{
    if (all.scene.event.type == sfEvtKeyPressed
    && KP(sfKeyUp) && all.menu.current_pos > 0) {
        all.menu.current_pos -= 1;
    } if (all.scene.event.type == sfEvtKeyPressed
    && KP(sfKeyDown) && all.menu.current_pos < 3) {
        all.menu.current_pos += 1;
    } all = is_over(all);
    sfRenderWindow_clear(all.scene.window, sfColor_fromRGB(24,20,37));
    all = is_pressed(all);
    return all;
}
