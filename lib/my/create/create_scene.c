/*
** EPITECH PROJECT, 2023
** create scene
** File description:
** creates the scene struct and fills it
*/

#include "my.h"

static page_t create_background(page_t scene)
{
    scene.back_tex = sfTexture_createFromFile("assets/World.png", NULL);
    scene.coll_tex = sfTexture_createFromFile("assets/world_coll.png", NULL);
    scene.end = sfTexture_createFromFile("assets/End.png", NULL);
    scene.game_over = sfTexture_createFromFile("assets/Lost.png", NULL);
    scene.back = sfSprite_create();
    sfSprite_setTexture(scene.back, scene.back_tex, sfFalse);
    return scene;
}

page_t create_scene(void)
{
    page_t scene;
    char *name = "My_RPG";
    scene.clock = sfClock_create();
    sfVideoMode param = {1920, 1080, 32};
    scene.window = sfRenderWindow_create(param, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(scene.window, 60);
    sfRenderWindow_setMouseCursorVisible(scene.window, sfFalse);
    scene = create_background(scene);
    scene.name = sfSprite_create();
    scene.name_t = sfTexture_createFromFile("assets/Miniventure.png", NULL);
    scene.is_won = false;
    scene.is_lost = false;
    sfSprite_setTexture(scene.name, scene.name_t, sfFalse);
    return scene;
}
