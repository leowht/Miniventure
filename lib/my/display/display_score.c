/*
** EPITECH PROJECT, 2023
** get_score_pos
** File description:
** gets the position of the score
*/

#include "my.h"

void display_score(all_t *all)
{
    sfVector2f p_pos = sfSprite_getPosition(all->play.player);
    p_pos.y += 2;
    if (all->score.i_score >= 10)
        p_pos.x -= 9;
    sfText_setPosition(all->score.t_score, p_pos);
    sfRenderWindow_drawText(all->scene.window, all->score.t_score, NULL);
    return;
}
