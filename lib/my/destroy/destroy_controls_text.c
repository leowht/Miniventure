/*
** EPITECH PROJECT, 2023
** destroy_control_text
** File description:
** destroy control text
*/

#include "my.h"

void destroy_controls_text(controls_pan_t controls)
{
    sfText_destroy(controls.up_key);
    sfText_destroy(controls.left_key);
    sfText_destroy(controls.down_key);
    sfText_destroy(controls.right_key);
    sfText_destroy(controls.control_key);
    sfText_destroy(controls.exit_key);
    sfText_destroy(controls.title);
    sfText_destroy(controls.inv_key);
    sfText_destroy(controls.spacebar_key);
}
