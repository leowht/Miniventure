/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** show_inventory_obj.c
*/

#include "my.h"

void show_objects(sfRenderWindow *window, sfSprite* inventory,
list_t* object_list)
{
    int columne = 0;
    list_node_t *node = object_list->head;
    sfVector2f position = sfSprite_getPosition(inventory);
    position.x += 176;
    position.y += 72;
    while (node != NULL) {
        if (columne > 0)
            position.x += 40;
        sfSprite_setPosition(node->object, position);
        sfRenderWindow_drawSprite(window, node->object, NULL);
        columne++;
        if (columne > 2) {
            position = sfSprite_getPosition(inventory);
            position.x += 176;
            position.y += (72 + 32);
            columne = 0;
        } node = node->next;
    }
}
