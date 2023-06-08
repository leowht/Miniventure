/*
** EPITECH PROJECT, 2023
** create_all_mobs
** File description:
** creates all mobs in the linked list
*/

#include "my.h"

list_mob_t *create_all_mobs(void)
{
    list_mob_t *list = create_mob_list();
    char *all_pos_txt = load_file_in_mem("assets/Combat/pos_mobs.txt");
    char **all_pos = my_str_to_word_array(all_pos_txt, '\n');
    char **a_pos;
    sfVector2f pos = {0, 0};

    for (int i = 0; all_pos[i] != NULL; i++) {
        a_pos = my_str_to_word_array(all_pos[i], ' ');
        pos.x = my_getnbr(a_pos[0]);
        pos.y = my_getnbr(a_pos[1]);
        if (i % 2 == 0)
            add_mob(list, create_mob(pos, "assets/Mobs/goblin_.png", 256));
        else
            add_mob(list, create_mob(pos, "assets/Mobs/golem_.png", 256));
    }
    return list;
}
