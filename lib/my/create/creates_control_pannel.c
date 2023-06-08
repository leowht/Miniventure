/*
** EPITECH PROJECT, 2023
** control_pannel
** File description:
** control_pannel
*/

#include "my.h"

controls_pan_t create_controls_pannel(controls_pan_t pannel)
{
    pannel.pannel_tex = sfTexture_createFromFile("assets\
/menu/controls_key.png", NULL);
    pannel.pannel = sfSprite_create();
    sfSprite_setPosition(pannel.pannel,
(sfVector2f){1100, 4475});
    sfSprite_setTexture(pannel.pannel, pannel.pannel_tex
, sfFalse);
    pannel.b_none = sfTexture_createFromFile("assets/\
menu/button1.png", NULL);
    pannel.b_hover = sfTexture_createFromFile("assets/\
menu/button2.png", NULL);
    pannel.b_pressed = sfTexture_createFromFile("assets/\
menu/button3.png",
NULL);
    pannel.b_exit = create_button((sfVector2f){1450, 4950}\
, (sfVector2f){500, 0}, "assets/menu/exit.png");
    sfSprite_setTexture(pannel.b_exit.button, pannel.b_none, sfTrue);
    pannel.is_open = true;
    return pannel;
}
