/*
** EPITECH PROJECT, 2022
** create_all
** File description:
** creates all structs
*/

#include "my.h"

static all_t npc_group(all_t all)
{
    all.npc_list = nlist_create();
    npc_t npc = create_npc(npc, (sfVector2f){1815, 4800},
    "assets/Sprite/playerSprites_/CYPHER_SpriteSheet.png");
    list_add_npc(all.npc_list, npc.npc, npc.coords, "KILL 15 MONSTERS");
    npc = create_npc(npc, (sfVector2f){2975, 3560},
    "assets/Sprite/playerSprites_/mPlayer_ [dwarf].png");
    list_add_npc(all.npc_list, npc.npc, npc.coords, "HELP ME !");
    npc = create_npc(npc, (sfVector2f){3889, 4772},
    "assets/Sprite/taigaSprites_/thief_.png");
    list_add_npc(all.npc_list, npc.npc, npc.coords, "NICE TRY");
    npc = create_npc(npc, (sfVector2f){2679, 3364},
    "assets/Sprite/playerSprites_/mPlayer_ [elf].png");
    list_add_npc(all.npc_list, npc.npc, npc.coords, "AAAAAAAAAAH !");
    all.play.is_near = 0;
    all.menu.is_open = true;
    all.menu.settings.is_open = false;
    all.menu.current_pos = 0;
    all.menu.settings.is_return = 0;
    return all;
}

all_t insert_remaining(all_t all)
{
    all.object_list = list_create();
    all.score = create_score();
    create_objects(all.object_list);
    all = npc_group(all);
    return all;
}

all_t create_all(all_t all)
{
    if (checker_assets(&all) == 1)
        return all;
    all.scene = create_scene();
    all.play = create_player(all.scene);
    player_stat_t player_stat = get_stat(player_stat,
    "assets/stat/cypher_stat.txt");
    inventory_t inventory = create_inventory(inventory);
    combat_t combat = create_combat(combat);
    menu_t menu = create_menu(menu);
    controls_pan_t pannel = create_controls_pannel(pannel);
    all.player_stat = player_stat;
    create_view(&all.play, all.scene.window);
    all.inv = inventory;
    all.combat = combat;
    all.menu = menu;
    all.controls = pannel;
    all.mobs = create_all_mobs();
    all = insert_remaining(all);
    return all;
}
