/*
** EPITECH PROJECT, 2022
** analyse_events
** File description:
** takes an event as a param and acts depending on it
*/

#include "my.h"

static all_t analyse_events(sfRenderWindow *window, sfEvent event, all_t all)
{
    switch (event.type) {
        case sfEvtClosed:
            close_window(window);
            break;
        default:
            break;
    }
    return all;
}

static all_t analyse_key(sfEvent event, all_t all)
{
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft) {
        all.scene.cursor_coords.x = event.mouseButton.x;
        all.scene.cursor_coords.y = event.mouseButton.y;
        is_npc_clicked(all, all.npc_list);
    } if (event.type == sfEvtKeyPressed && KP(sfKeyI)) {
        sfSprite_setPosition(all.inv.inv,
        sfSprite_getPosition(all.play.player));
        all.inv.is_open = !all.inv.is_open;
    } if (event.type == sfEvtKeyPressed && KP(sfKeyC)) {
        sfSprite_setPosition(all.inv.inv,
        sfSprite_getPosition(all.play.player));
        all.controls.is_open = !all.controls.is_open;
    }
    return all;
}

all_t do_events(all_t all)
{
    all = is_npc_clicked(all, all.npc_list);
    if (all.combat.is_combat) {
        all = combat_events(all);
    }
    if (!all.scene.is_won || !all.scene.is_lost) {
        all = analyse_events(all.scene.window, all.scene.event, all);
        all = analyse_key(all.scene.event, all);
    }
    return all;
}
