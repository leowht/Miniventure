/*
** EPITECH PROJECT, 2023
** game_loop
** File description:
** contains the main game loop, movements && others
*/

#include "my.h"

static sfFloatRect bounds(sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    bounds.top += 7;
    bounds.left += 7;
    bounds.height -= 14;
    bounds.width -= 14;
    return bounds;
}

void is_mob_met(all_t *all, list_mob_t *mob)
{
    sfFloatRect mob_bounds;
    sfFloatRect player_bounds = bounds(all->play.player);
    node_mob_t *node = mob->head;

    while (node != NULL) {
        mob_bounds = bounds(node->c_mob.mob);
        if (sfFloatRect_intersects(&mob_bounds, &player_bounds, NULL)) {
            all->combat.is_combat = true;
            set_combat_scene(all, &node->c_mob);
            break;
        }
        node = node->next;
    }
}

all_t game_loop(all_t all)
{
    if (all.scene.seconds > 0.1) {
        list_npc_t *npc_node = all.npc_list->head;
        while (npc_node != NULL) {
            animate_npc(npc_node);
            npc_node = npc_node->next;
        } animate_mob(all.mobs);
        animate_player(&all, &all.play);
    }
    if (is_moving(all.scene.event))
        move(&all.play);
    if (!is_moving(all.scene.event))
        idle_animation(&all.play);
    if (all.combat.is_combat == false)
        all = get_pos_player(all);
    is_mob_met(&all, all.mobs);
    return all;
}
