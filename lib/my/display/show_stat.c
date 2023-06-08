/*
** EPITECH PROJECT, 2023
** show_stat
** File description:
** show stat in inventory
*/

#include "my.h"

void display_pv(sfText *pv_t, sfRenderWindow *window,
sfSprite *inventory, sfFont *font)
{
    sfVector2f pos = sfSprite_getPosition(inventory);
    sfVector2f scale = {0.5, 0.5};

    pos.x += 125;
    pos.y += 39;
    sfText_setPosition(pv_t, pos);
    sfText_setScale(pv_t, scale);
    sfText_setFont(pv_t, font);
    sfRenderWindow_drawText(window, pv_t, NULL);
}

void display_text(player_stat_t *stat, sfRenderWindow *window,
sfSprite *inventory)
{
    sfFont *font = sfFont_createFromFile("assets/Font/font.ttf");

    display_pv(stat->pv_t, window, inventory, font);
    display_att(stat->att_t, window, inventory, font);
    display_def(stat->def_t, window, inventory, font);
    display_lck(stat->lck_t, window, inventory, font);
}

void set_the_color(player_stat_t *stat, sfRenderWindow *window,
sfSprite *inventory)
{
    sfText_setColor(stat->pv_t, sfBlack);
    sfText_setColor(stat->att_t, sfBlack);
    sfText_setColor(stat->def_t, sfBlack);
    sfText_setColor(stat->lck_t, sfBlack);
    sfText_setColor(stat->xp_t, sfBlack);
    sfText_setColor(stat->lvl_t, sfBlack);
    display_text(stat, window, inventory);
}

void set_the_text(player_stat_t *stat, sfRenderWindow *window,
sfSprite *inventory)
{
    sfText_setString(stat->pv_t, my_int_to_str(stat->pv));
    sfText_setString(stat->att_t, my_int_to_str(stat->att));
    sfText_setString(stat->def_t, my_int_to_str(stat->def));
    sfText_setString(stat->lck_t, my_int_to_str(stat->lck));
    sfText_setString(stat->xp_t, my_int_to_str(stat->xp));
    sfText_setString(stat->lvl_t, my_int_to_str(stat->lvl));
    set_the_color(stat, window, inventory);
}

void show_stat_inv(player_stat_t *stat, sfRenderWindow *window,
sfSprite *inventory)
{
    stat->pv_t = sfText_create();
    stat->att_t = sfText_create();
    stat->def_t = sfText_create();
    stat->lck_t = sfText_create();
    stat->xp_t = sfText_create();
    stat->lvl_t = sfText_create();
    set_the_text(stat, window, inventory);
    destroy_stat_txt(stat);
}
