/*
** EPITECH PROJECT, 2023
** list_mob_remove
** File description:
** removes a mob from the mob linked list
*/

#include "my.h"

static void free_mob_struct(mob_t *mob)
{
    sfTexture_destroy(mob->mob_text);
    sfSprite_destroy(mob->mob);
    return;
}

static void list_remove_node(list_mob_t *list, node_mob_t *node)
{
    list->size--;
    if (list->head == node)
        list->head = node->next;
    if (list->tail == node)
        list->tail = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
    free(node);
}

void list_mob_remove(list_mob_t *list, unsigned int index)
{
    node_mob_t *node;

    if (list == NULL) {
        write(1, "list_remove : list == NULL\n", 27);
        return;
    }
    node = list_get_the_mob_node(list, index);
    if (node != NULL) {
        free_mob_struct(&node->c_mob);
        list_remove_node(list, node);
    }
}

list_mob_t *create_mob_list(void)
{
    list_mob_t *list = malloc(sizeof(nlist_t));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
