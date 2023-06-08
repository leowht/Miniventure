/*
** EPITECH PROJECT, 2023
** combat_events
** File description:
** contains functions that handles combat events
*/

#include "my.h"

void fight_button_hover(all_t *all)
{
    all->combat.fight.state = HOVER;
    EVENT(all->combat.fight, all->combat.b_hover);
    all->combat.shield.state = NONE;
    EVENT(all->combat.shield, all->combat.b_none);
    return;
}

void shield_button_hover(all_t *all)
{
    all->combat.shield.state = HOVER;
    EVENT(all->combat.shield, all->combat.b_hover);
    all->combat.fight.state = NONE;
    EVENT(all->combat.fight, all->combat.b_none);
    return;
}

all_t combat_events(all_t all)
{
    if (all.scene.event.type == sfEvtKeyPressed && KP(sfKeyLeft))
        fight_button_hover(&all);
    if (all.scene.event.type == sfEvtKeyPressed && KP(sfKeyRight))
        shield_button_hover(&all);
    if (all.scene.event.type == sfEvtKeyPressed && all.combat.player_turn &&
    KP(sfKeySpace) && all.combat.fight.state == HOVER)
        fight(&all);
    else if (all.combat.fight.state == PRESSED && !KP(sfKeySpace))
        fight_button_hover(&all);
    if (all.scene.event.type == sfEvtKeyPressed && all.combat.player_turn &&
    KP(sfKeySpace) && all.combat.shield.state == HOVER)
        shield(&all);
    else if (all.combat.shield.state == PRESSED && !KP(sfKeySpace))
        shield_button_hover(&all);
    return all;
}
