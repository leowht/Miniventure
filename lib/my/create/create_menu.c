/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** create_menu.c
*/

#include "my.h"

static menu_t set_menu_texture(menu_t menu)
{
    sfSprite_setTexture(menu.b_start.button, menu.b_none, sfTrue);
    sfSprite_setTexture(menu.b_resume.button, menu.b_none, sfTrue);
    sfSprite_setTexture(menu.b_settings.button, menu.b_none, sfTrue);
    sfSprite_setTexture(menu.b_exit.button, menu.b_none, sfTrue);
    return menu;
}

menu_t create_menu(menu_t menu)
{
    menu.back_tex = sfTexture_createFromFile("assets/menu/menu.png", NULL);
    menu.back = sfSprite_create();
    sfSprite_setPosition(menu.back, (sfVector2f){1100, 4475});
    sfSprite_setTexture(menu.back, menu.back_tex, sfFalse);
    menu.b_none = sfTexture_createFromFile("assets/menu/button1.png", NULL);
    menu.b_hover = sfTexture_createFromFile("assets/menu/button2.png", NULL);
    menu.b_pressed = sfTexture_createFromFile("assets/menu/button3.png",
    NULL);
    menu.b_start = create_button((sfVector2f){1450, 4650},
    (sfVector2f){1000, 0}, "assets/menu/play.png");
    menu.b_resume = create_button((sfVector2f){1450, 4750},
    (sfVector2f){700, 0}, "assets/menu/resume.png");
    menu.b_settings = create_button((sfVector2f){1450, 4850},
    (sfVector2f){500, 0}, "assets/menu/settings.png");
    menu.b_exit = create_button((sfVector2f){1450, 4950},
    (sfVector2f){1000, 0}, "assets/menu/exit.png");
    menu = set_menu_texture(menu);
    return menu;
}
