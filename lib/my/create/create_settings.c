/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** create_settings.c
*/

#include "my.h"

static menu_t set_settings_texture(menu_t menu)
{
    sfSprite_setTexture(menu.settings.b_plus.button, menu.b_none, sfTrue);
    sfSprite_setTexture(menu.settings.b_minus.button, menu.b_none, sfTrue);
    sfSprite_setTexture(menu.settings.b_return.button, menu.b_none, sfTrue);
    return menu;
}

menu_t create_settings(menu_t menu)
{
    menu.settings.b_none =
    sfTexture_createFromFile("assets/menu/square_button1.png", NULL);
    menu.settings.b_hover =
    sfTexture_createFromFile("assets/menu/square_button2.png", NULL);
    menu.settings.b_pressed =
    sfTexture_createFromFile("assets/menu/square_button3.png", NULL);
    menu.settings.b_none_rect =
    sfTexture_createFromFile("assets/menu/button1.png", NULL);
    menu.settings.b_hover_rect =
    sfTexture_createFromFile("assets/menu/button2.png", NULL);
    menu.settings.b_pressed_rect =
    sfTexture_createFromFile("assets/menu/button3.png", NULL);
    menu.settings.b_plus = create_button((sfVector2f){1500, 4650},
    (sfVector2f){0, 0}, "assets/menu/plus.png");
    menu.settings.b_minus = create_button((sfVector2f){1700, 4650},
    (sfVector2f){0, 10}, "assets/menu/minus.png");
    menu.settings.b_return = create_button((sfVector2f){1450, 4950},
    (sfVector2f){700, 0}, "assets/menu/return.png");
    menu = set_settings_texture(menu);
    return menu;
}
