/*
** EPITECH PROJECT, 2023
** end
** File description:
** end
*/

#include "my.h"

void end_game(all_t *all)
{
    all->scene.is_won = true;
    sfSprite_setTexture(all->scene.back, all->scene.end, sfFalse);
    sfSprite_setPosition(all->play.player, (sfVector2f){465, 280});
    return;
}

void game_over(all_t *all)
{
    all->scene.is_lost = true;
    sfSprite_setTexture(all->scene.back, all->scene.game_over, sfFalse);
    sfSprite_setPosition(all->play.player, (sfVector2f){465, 280});
    return;
}
