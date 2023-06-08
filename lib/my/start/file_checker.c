/*
** EPITECH PROJECT, 2023
** file_checker
** File description:
** file_checker
*/

#include "my.h"

void check_path_get_stat_create_inv(all_t *all)
{
    int fd;
    if ((fd = open("assets/stat/cypher_stat.txt", O_RDONLY)) <= -1) {
        write(1, "/!\\MISSING FILE : assets/stat/cypher_stat.txt ! \n", 50);
        all->status = 1;
        close(fd);
    }
    if (sfTexture_createFromFile("assets/objects_icon/sword_wood.png",
NULL) == NULL) {
        write(1, "/!\\MISSING FILE : assets/objects_icon/\
sword_wood.png ! \n", 57);
        all->status = 1;
    }
    if (sfTexture_createFromFile("assets/inventory_test.png", NULL) == NULL) {
        write(1, "/!\\MISSING FILE : assets/inventory_test.png ! \n", 48);
        all->status = 1;
    }
}

void check_path_create_scene_create_player(all_t *all)
{
    int fd;
    if (sfTexture_createFromFile("assets/World.png", NULL) == NULL) {
        write(1, "/!\\MISSING FILE : assets/World.png ! \n", 39);
        all->status = 1;
    }
    if (sfTexture_createFromFile("assets/world_coll.png", NULL) == NULL) {
        write(1, "/!\\MISSING FILE : assets/world_coll.png ! \n", 44);
        all->status = 1;
    }
    if ((fd = open("assets/Sprite/playerSprites_/\
bandit_.png", O_RDONLY)) <= -1) {
        write(1, "/!\\MISSING FILE : assets/Sprite/playerSprites\
_/bandit_.png ! \n", 63);
        all->status = 1;
        close(fd);
    }
}

void check_path_create_all(all_t *all)
{
    int fd;
    if ((fd = open("assets/Mobs/goblin_.png", O_RDONLY)) <= -1) {
        write(1,
"/!\\MISSING FILE : assets/Sprite/caveSprites_/goblin_.png ! \n",
60);
        all->status = 1;
        close(fd);
    }
    if ((fd = open("assets/Sprite/playerSprites_/CYPHER_SpriteSheet.png",
    O_RDONLY)) <= -1) {
        write(1,
"/!\\MISSING FILE : assets/Sprite/playerSprites_/CYPHER_SpriteSheet.\
png ! \n", 71);
        all->status = 1;
        close(fd);
    }
}

void check_path_create_combat(all_t *all)
{
    if (sfTexture_createFromFile("assets/combat.png", NULL) == NULL) {
        write(1, "/!\\MISSING FILE : assets/combat.png ! \n", 39);
        all->status = 1;
    }
    if (sfTexture_createFromFile("assets/Combat/none.png", NULL) == NULL) {
        write(1, "/!\\MISSING FILE : assets/Combat/none.png ! \n", 45);
        all->status = 1;
    }
    if (sfTexture_createFromFile("assets/Combat/hover.png", NULL) == NULL) {
        write(1, "/!\\MISSING FILE : assets/Combat/hover.png ! \n", 46);
        all->status = 1;
    }
    if (sfTexture_createFromFile("assets/Combat/pressed.png",NULL) == NULL) {
        write(1, "/!\\MISSING FILE : assets/Combat/pressed.png ! \n", 45);
        all->status = 1;
    }
}

int checker_assets(all_t *all)
{
    int fd = 0;
    all->status = 0;
    check_path_create_combat(all);
    check_path_create_all(all);
    check_path_create_scene_create_player(all);
    check_path_get_stat_create_inv(all);
    if ((fd = open("assets/pos/player_pos.txt", O_RDONLY)) <= -1) {
        write(1, "/!\\MISSING FILE : assets/pos/player_pos.txt\n", 45);
        all->status = 1;
        close(fd);
    }
    if ((fd = open("assets/Combat/pos_mobs.txt", O_RDONLY)) <= -1) {
        write(1, "/!\\MISSING FILE : assets/Combat/pos_mobs.txt\n", 45);
        all->status = 1;
        close(fd);
    }
    return all->status;
}
