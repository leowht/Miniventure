/*
** EPITECH PROJECT, 2023
** animate_player
** File description:
** animates the player
*/

#include "my.h"

static void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value) {
        rect->left = 0;
    }
    return;
}

void animate_player(all_t *all, player_t *player)
{
    move_rect(&player->rect, player->offset, player->val_max);
    sfSprite_setTextureRect(player->player, player->rect);
    sfClock_restart(all->scene.clock);
    return;
}

void animate_mob(list_mob_t *mobs)
{
    node_mob_t *node = mobs->head;
    while (node != NULL) {
        move_rect(&node->c_mob.rect, node->c_mob.offset, node->c_mob.val_max);
        sfSprite_setTextureRect(node->c_mob.mob, node->c_mob.rect);
        node = node->next;
    }
    return;
}

void animate_npc(list_npc_t *npc)
{
    move_rect(&npc->rect, 32, 128);
    sfSprite_setTextureRect(npc->npc, npc->rect);
    return;
}
