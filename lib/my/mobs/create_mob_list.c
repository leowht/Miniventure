/*
** EPITECH PROJECT, 2023
** create_mob_list
** File description:
** creates empty mob list
*/

#include "my.h"

static node_mob_t *list_get_mob_node(list_mob_t *list, unsigned int index)
{
    node_mob_t *node;
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

mob_t list_get_mob(list_mob_t *list, unsigned int index)
{
    node_mob_t *node = list_get_mob_node(list, index);

    if (node != NULL)
        return node->c_mob;
}

node_mob_t *list_get_the_mob_node(list_mob_t *list, unsigned int index)
{
    node_mob_t *node = list_get_mob_node(list, index);

    if (node != NULL)
        return node;
}

static unsigned int list_add_node(list_mob_t *list, node_mob_t *node)
{
    list->size++;
    node->next = NULL;
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
        return 0;
    }
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
    return list->size - 1;
}

unsigned int add_mob(list_mob_t *list, mob_t value)
{
    node_mob_t *node;

    if (list == NULL) {
        write(1, "list_add : list of value is NULL\n", 33);
        return 0;
    }
    node = malloc(sizeof(node_mob_t));
    node->c_mob = value;
    node->next = NULL;
    node->prev = NULL;
    return list_add_node(list, node);
}
