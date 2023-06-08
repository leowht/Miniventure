/*
** EPITECH PROJECT, 2023
** combat_scene
** File description:
** functions that modifies the struct to display te combat scene or
** the main game
*/

#include "my.h"

void set_combat_scene(all_t *all, mob_t *mob)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(all->scene.back);

    all->play.pos = sfSprite_getPosition(all->play.player);
    all->combat.mob = mob;
    sfSprite_setTexture(all->scene.back, all->combat.back_tex, sfTrue);
    sfSprite_setPosition(all->play.player, (sfVector2f){230 , 170});
    idle_animation(&all->play);
    sfSprite_setPosition(mob->mob, (sfVector2f){690 , 170});
    sfView_setCenter(all->play.view, (sfVector2f){(pos.top + 479),
    (pos.left + 270)});
    sfRenderWindow_setView(all->scene.window, all->play.view);
    return;
}

bool is_same_mob(mob_t *comp, mob_t *mob)
{
    if (comp->coords.x == mob->coords.x && comp->coords.y == mob->coords.y)
        return true;
    return false;
}

void destroy_mob(list_mob_t *all_mobs, mob_t *mob)
{
    int pos = 0;
    node_mob_t *node = all_mobs->head;

    for (; !is_same_mob(&node->c_mob, mob); pos++) {
        node = node->next;
    }
    list_mob_remove(all_mobs, pos);
    return;
}

void exit_combat_scene (all_t *all)
{
    if (all->player_stat.pv <= 0) {
        game_over(all);
        return;
    }
    sfSprite_setPosition(all->play.player, all->play.pos);
    sfSprite_setTexture(all->scene.back, all->scene.back_tex, sfTrue);
    destroy_mob(all->mobs, all->combat.mob);
    update_stat(&all->player_stat);
    all->combat.mob = NULL;
    set_view(&all->play, all->scene.window);
    all->score.i_score += 1;
    sfText_setString(all->score.t_score, my_int_to_str(all->score.i_score));
    return;
}
