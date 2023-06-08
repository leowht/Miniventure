/*
** EPITECH PROJECT, 2022
** list_get
** File description:
** gets the content of a node
*/

#include "my.h"

list_node_t *list_get_node(list_t *list, unsigned int index)
{
    list_node_t *node;
    unsigned int current = 0;

    if (list == NULL) {
        write(1, "list_get_node : list == NULL\n", 29);
        return NULL;
    }
    node = list->head;
    if (node == NULL) {
        write(1, "list_get_node : node == NULL\n", 29);
        return NULL;
    }
    while (node != NULL && current < index) {
        current++;
        node = node->next;
    }
    return node;
}

sfSprite *list_get(list_t *list, unsigned int index)
{
    list_node_t *node = list_get_node(list, index);

    if (node != NULL)
        return node->object;
    return NULL;
}
