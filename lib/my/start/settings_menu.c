/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** settings_menu.c
*/
#include "my.h"

all_t settings_loop(all_t all)
{
    sfRenderWindow_clear(all.scene.window, sfColor_fromRGB(24,20,37));
    all.menu = create_settings(all.menu);
    all.menu.current_pos = 0;
    while (all.menu.settings.is_open == true &&
    sfRenderWindow_isOpen(all.scene.window)) {
        while (sfRenderWindow_pollEvent(all.scene.window, &all.scene.event)) {
            all = do_events(all);
            all = settings_events(all);
            display_the_settings(all.scene.window, all.menu);
            sfRenderWindow_display(all.scene.window);
        }
    }
    return all;
}
