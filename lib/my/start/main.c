/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** main.c
*/

#include "my.h"

all_t main_loop(all_t all)
{
    all.scene.time = sfClock_getElapsedTime(all.scene.clock);
    all.scene.seconds = all.scene.time.microseconds / 1000000.0;
    if (all.player_stat.pv == 0)
        all.scene.is_lost = true;
    while (sfRenderWindow_pollEvent(all.scene.window, &all.scene.event)) {
        all = do_events(all);
    }
    if (!all.inv.is_open && !all.combat.is_combat) {
        set_view(&all.play, all.scene.window);
        all = game_loop(all);
    }
    if (all.inv.is_open)
        all = inventory_loop(all);
    if (all.combat.is_combat)
        all = combat_loop(all);
    if (all.score.i_score >= 15 || all.scene.is_won)
        end_game(&all);
    all = display(all);
    return all;
}

sfVector2f get_player_pos(void)
{
    char *path = "assets/pos/player_pos.txt";
    int fd = open(path, O_RDONLY);
    char *buf;
    char **pos_f;
    struct stat num;
    sfVector2f pos;

    stat(path, &num);
    buf = malloc(sizeof(char) * (num.st_size + 1));
    read(fd, buf, num.st_size);
    pos_f = my_str_to_word_array(buf, ' ');
    pos.x = my_getnbr(pos_f[0]);
    pos.y = my_getnbr(pos_f[1]);
    return pos;
}

static all_t after_menu_loop(all_t all)
{
    while (sfRenderWindow_isOpen(all.scene.window)){
        all = main_loop(all);
    } if (all.combat.is_combat == false)
        all = get_pos_player(all);
    destroy(all);
    return all;
}

int main(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        flag_h();
        return 0;
    } all_t all = create_all(all);
    if (all.status == 1)
        return 84;
    sfSprite_setPosition(all.play.player, (sfVector2f){1615, 4800});
    while (all.menu.is_open != false &&
    sfRenderWindow_isOpen(all.scene.window)){
        while (sfRenderWindow_pollEvent(all.scene.window, &all.scene.event)) {
            all = do_events(all);
            all = menu_events(all);
            display_the_menu(all.scene.window, all.menu);
            sfRenderWindow_display(all.scene.window);
        }
    }
    all = after_menu_loop(all);
    return 0;
}
