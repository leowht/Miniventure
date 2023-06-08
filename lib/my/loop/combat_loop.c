/*
** EPITECH PROJECT, 2023
** combat_loop
** File description:
** contains the combat loop
*/

#include "my.h"

void actual_combat(all_t *all)
{
    if (all->combat.player_a == 0 && all->combat.mob_a == 0)
        atk_atk(all);
    if (all->combat.player_a == 0 && all->combat.mob_a == 1)
        atk_def(all);
    if (all->combat.player_a == 1 && all->combat.mob_a == 0)
        def_atk(all);
    if (all->combat.player_a == 1 && all->combat.mob_a == 1)
        def_def(all);
    return;
}

all_t combat_loop(all_t all)
{
    if (all.scene.seconds > 0.1) {
        animate_mob(all.mobs);
        animate_player(&all, &all.play);
    }
    if (!all.combat.player_turn)
        actual_combat(&all);
    if (all.combat.mob->hp <= 0 || all.player_stat.pv <= 0) {
        all.combat.is_combat = false;
        exit_combat_scene(&all);
    }
    return all;
}
