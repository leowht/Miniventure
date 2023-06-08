/*
** EPITECH PROJECT, 2022
** display
** File description:
** displays
*/

#include "my.h"

// void display_the_menu(sfRenderWindow *window, menu_t menu)
// {
//     sfRenderWindow_drawSprite(window, menu.back, NULL);
//     sfRenderWindow_drawSprite(window, menu.b_start.button,
//     NULL);
//     sfRenderWindow_drawSprite(window, menu.b_resume.button,
//     NULL);
//     sfRenderWindow_drawSprite(window, menu.b_settings.button,
//     NULL);
//     sfRenderWindow_drawSprite(window, menu.b_exit.button,
//     NULL);
//     sfRenderWindow_drawSprite(window, menu.b_start.text,
//     NULL);
//     sfRenderWindow_drawSprite(window, menu.b_resume.text,
//     NULL);
//     sfRenderWindow_drawSprite(window, menu.b_settings.text,
//     NULL);
//     sfRenderWindow_drawSprite(window, menu.b_exit.text,
//     NULL);
// }

void display_the_fight(sfRenderWindow *window, combat_t fight)
{
    sfRenderWindow_drawSprite(window, fight.fight.button,
    NULL);
    sfRenderWindow_drawSprite(window, fight.shield.button,
    NULL);
    sfRenderWindow_drawSprite(window, fight.shield.text,
    NULL);
    sfRenderWindow_drawSprite(window, fight.fight.text,
    NULL);
}

static void display_npc(all_t all, nlist_t *npc_list)
{
    list_npc_t *npc_node = npc_list->head;
    while (npc_node != NULL) {
        sfRenderWindow_drawSprite(all.scene.window, npc_node->npc, NULL);
        npc_node = npc_node->next;
    }
}

void display_mobs(all_t all, list_mob_t *mobs)
{
    node_mob_t *node = mobs->head;
    while (node != NULL) {
        sfRenderWindow_drawSprite(all.scene.window, node->c_mob.mob, NULL);
        node = node->next;
    }
    return;
}

all_t display(all_t all)
{
    reload_map(all);
    if (!all.combat.is_combat) {
        display_npc(all, all.npc_list);
        display_score(&all);
    }
    if (all.inv.is_open) {
        sfRenderWindow_drawSprite(all.scene.window, all.inv.inv, NULL);
        show_objects(all.scene.window, all.inv.inv, all.object_list);
        show_stat_inv(&all.player_stat, all.scene.window, all.inv.inv);
    } if (all.combat.is_combat) {
        display_the_fight(all.scene.window, all.combat);
    } if (all.play.is_near == true) {
        sfRenderWindow_drawRectangleShape(all.scene.window,
        all.npc_text.bulle, NULL);
        sfRenderWindow_drawText(all.scene.window, all.npc_text.text, NULL);
    } if (all.controls.is_open == true) {
        sfRenderWindow_drawSprite(all.scene.window, all.controls.pannel, NULL);
        display_controls(all.scene.window, all.controls);
    } sfRenderWindow_display(all.scene.window);
    return all;
}
