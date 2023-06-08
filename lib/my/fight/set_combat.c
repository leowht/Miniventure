/*
** EPITECH PROJECT, 2023
** set_combat
** File description:
** contains functions that sets the combat actions
*/

#include "../../../include/my.h"

int get_mob_action(void)
{
    int action;

    srand(time(0));
    action = rand() % 3;
    if (action == 0 || action == 1)
        return 0;
    return 1;
}

void shield(all_t *all)
{
    all->combat.shield.state = PRESSED;
    all->combat.player_turn = false;
    EVENT(all->combat.shield, all->combat.b_pressed);
    all->combat.player_a = DEF;
    all->combat.mob_a = get_mob_action();
    return;
}

void fight(all_t *all)
{
    all->combat.fight.state = PRESSED;
    all->combat.player_turn = false;
    EVENT(all->combat.fight, all->combat.b_pressed);
    all->combat.player_a = ATK;
    all->combat.mob_a = get_mob_action();
    return;
}
