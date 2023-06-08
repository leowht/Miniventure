/*
** EPITECH PROJECT, 2023
** display_controls
** File description:
** display_controls
*/

#include "my.h"

void display_right_key(controls_pan_t controls, sfRenderWindow *window,
sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(controls.pannel);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 575;
    pos.y += 275;
    sfText_setPosition(controls.right_key, pos);
    sfText_setScale(controls.right_key, scale);
    sfText_setFont(controls.right_key, font);
    sfRenderWindow_drawText(window, controls.right_key, NULL);
}

void display_controls_txt(sfRenderWindow *window, controls_pan_t controls)
{
    sfFont *font = sfFont_createFromFile("assets/Font/font.ttf");

    display_right_key(controls, window, font);
    display_left_key(controls, window, font);
    display_down_key(controls, window, font);
    display_up_key(controls, window, font);
    display_title_control(controls, window, font);
    display_c_key(controls, window, font);
    display_exit_key(controls, window, font);
    display_spacebar_key(controls, window, font);
    display_inv_key(controls, window, font);
}

void set_color_controls(sfRenderWindow *window, controls_pan_t controls)
{
    sfText_setColor(controls.up_key, sfBlack);
    sfText_setColor(controls.down_key, sfBlack);
    sfText_setColor(controls.left_key, sfBlack);
    sfText_setColor(controls.right_key, sfBlack);
    sfText_setColor(controls.control_key, sfBlack);
    sfText_setColor(controls.title, sfBlack);
    sfText_setColor(controls.exit_key, sfBlack);
    sfText_setColor(controls.spacebar_key, sfBlack);
    sfText_setColor(controls.inv_key, sfBlack);
    display_controls_txt(window, controls);
}

void set_the_controls_string(sfRenderWindow *window, controls_pan_t controls)
{
    sfText_setString(controls.up_key, "go up");
    sfText_setString(controls.down_key, "go down");
    sfText_setString(controls.left_key, "go left");
    sfText_setString(controls.right_key, "go right");
    sfText_setString(controls.control_key, "c : open/exit controls page");
    sfText_setString(controls.exit_key, "x : exit controls page");
    sfText_setString(controls.title, "~~controls~~");
    sfText_setString(controls.spacebar_key, "spacebar : interact \
with button");
    sfText_setString(controls.inv_key, "i : open/close inventory");
    set_color_controls(window, controls);
}

void display_controls(sfRenderWindow *window, controls_pan_t controls)
{
    controls.up_key = sfText_create();
    controls.down_key = sfText_create();
    controls.left_key = sfText_create();
    controls.right_key = sfText_create();
    controls.control_key = sfText_create();
    controls.exit_key = sfText_create();
    controls.title = sfText_create();
    controls.spacebar_key = sfText_create();
    controls.inv_key = sfText_create();
    set_the_controls_string(window, controls);
    destroy_controls_text(controls);
}
