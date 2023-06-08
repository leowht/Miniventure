/*
** EPITECH PROJECT, 2023
** create_score
** File description:
** creates and fills the score struct
*/

#include "my.h"

score_t create_score(void)
{
    score_t score;
    score.i_score = 0;
    score.font = sfFont_createFromFile("assets/Font/font.ttf");
    score.t_score = sfText_create();
    sfText_setString(score.t_score, my_int_to_str(score.i_score));
    sfText_setFillColor(score.t_score, sfColor_fromRGB(38, 41, 38));
    sfText_setFont(score.t_score, score.font);
    sfText_setCharacterSize(score.t_score, 10);
    return score;
}
