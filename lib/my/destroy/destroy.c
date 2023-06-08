/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** destroys all necessary elements
*/

#include "my.h"

void destroy(all_t all)
{
    list_npc_t *npc_node = all.npc_list->head;
    while (npc_node != NULL) {
        sfSprite_destroy(npc_node->npc);
        npc_node = npc_node->next;
    }
    save_stat(&all.player_stat);
    sfTexture_destroy(all.inv.inv_text);
    sfSprite_destroy(all.inv.inv);
    sfTexture_destroy(all.play.player_text);
    sfSprite_destroy(all.play.player);
    sfTexture_destroy(all.scene.back_tex);
    sfSprite_destroy(all.scene.back);
    sfClock_destroy(all.scene.clock);
    sfRenderWindow_destroy(all.scene.window);
    return;
}
