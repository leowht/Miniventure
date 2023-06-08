/*
** EPITECH PROJECT, 2023
** combat_actions
** File description:
** executes the combat turn
*/

#include "my.h"

int attack_luck(int luck)
{
    int throw;

    srand(time(0));
    throw = rand() % 10;
    if (throw < luck - 1)
        return 1;
    return 0;
}

void atk_atk(all_t *all)
{
    int p_attack = all->player_stat.att + attack_luck(all->player_stat.lck);
    int m_attack = all->combat.mob->atk + attack_luck(all->combat.mob->lck);

    all->player_stat.pv -= m_attack;
    if (all->player_stat.pv <= 0)
        all->player_stat.pv = 0;
    all->combat.mob->hp -= p_attack;
    all->combat.player_a = NOTHING;
    all->combat.mob_a = NOTHING;
    all->combat.player_turn = true;
    return;
}

void atk_def(all_t *all)
{
    int p_attack = all->player_stat.att + attack_luck(all->player_stat.lck);
    int final_attack = p_attack - all->combat.mob->def;

    if (final_attack < 0)
        final_attack = 0;
    all->combat.mob->hp -= final_attack;
    all->combat.player_a = NOTHING;
    all->combat.mob_a = NOTHING;
    all->combat.player_turn = true;
    return;
}

void def_atk(all_t *all)
{
    int m_attack = all->combat.mob->atk + attack_luck(all->combat.mob->lck);
    int final_attack = m_attack - all->player_stat.def;

    if (final_attack < 0)
        final_attack = 0;
    all->player_stat.pv -= final_attack;
    if (all->player_stat.pv <= 0)
        all->player_stat.pv = 0;
    all->combat.player_a = NOTHING;
    all->combat.mob_a = NOTHING;
    all->combat.player_turn = true;
    return;
}

void def_def(all_t *all)
{
    all->combat.player_a = NOTHING;
    all->combat.mob_a = NOTHING;
    all->combat.player_turn = true;
    return;
}
