/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** display_menu.c
*/

#include "my.h"

void display_the_settings(sfRenderWindow *window, menu_t menu)
{
    sfRenderWindow_drawSprite(window, menu.back, NULL);
    sfRenderWindow_drawSprite(window, menu.settings.b_plus.button,
    NULL);
    sfRenderWindow_drawSprite(window, menu.settings.b_minus.button,
    NULL);
    sfRenderWindow_drawSprite(window, menu.settings.b_return.button,
    NULL);
    sfRenderWindow_drawSprite(window, menu.settings.b_plus.text,
    NULL);
    sfRenderWindow_drawSprite(window, menu.settings.b_minus.text,
    NULL);
    sfRenderWindow_drawSprite(window, menu.settings.b_return.text,
    NULL);
}

void display_the_menu(sfRenderWindow *window, menu_t menu)
{
    sfRenderWindow_drawSprite(window, menu.back, NULL);
    sfRenderWindow_drawSprite(window, menu.b_start.button,
    NULL);
    sfRenderWindow_drawSprite(window, menu.b_resume.button,
    NULL);
    sfRenderWindow_drawSprite(window, menu.b_settings.button,
    NULL);
    sfRenderWindow_drawSprite(window, menu.b_exit.button,
    NULL);
    sfRenderWindow_drawSprite(window, menu.b_start.text,
    NULL);
    sfRenderWindow_drawSprite(window, menu.b_resume.text,
    NULL);
    sfRenderWindow_drawSprite(window, menu.b_settings.text,
    NULL);
    sfRenderWindow_drawSprite(window, menu.b_exit.text,
    NULL);
}
