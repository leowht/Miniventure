/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** is_npc_clicked.c
*/

#include "my.h"

all_t is_npc_clicked(all_t all, nlist_t* npc_list)
{
    list_npc_t *npc_node = npc_list->head;
    while (npc_node != NULL) {
        sfFloatRect npc_bounds = sfSprite_getGlobalBounds(npc_node->npc);
        sfFloatRect player_bounds = sfSprite_getGlobalBounds(all.play.player);
        if (sfFloatRect_intersects(&npc_bounds, &player_bounds, NULL) &&
        all.play.is_near == false) {
            all.play.is_near = true;
            all = create_npc_texte(all,npc_node->npc, npc_node->npc_text);
            return all;
        } if (sfFloatRect_intersects(&npc_bounds, &player_bounds, NULL))
            return all;
        else
        npc_node = npc_node->next;
    }
    if (all.play.is_near == true)
        all = destroy_npc_texte(all);
    all.play.is_near = false;
    return all;
}
