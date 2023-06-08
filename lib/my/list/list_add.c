/*
** EPITECH PROJECT, 2022
** list_add
** File description:
** adds to a list
*/

#include "my.h"

static unsigned int list_add_node(list_t *list, list_node_t *node)
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

unsigned int list_add(list_t *list, void *value)
{
    list_node_t *node;

    if (list == NULL || value == NULL) {
        write(1, "list_add : list of value is NULL\n", 33);
        return 0;
    }
    node = malloc(sizeof(list_node_t));
    node->luck_st = 0;
    node->atk_st = 0;
    node->def_st = 0;
    node->life_st = 0;
    node->object = sfSprite_create();
    node->object_tex = value;
    sfSprite_setTexture(node->object, value, sfTrue);
    node->next = NULL;
    node->prev = NULL;
    return list_add_node(list, node);
}

static unsigned int list_add_npc_node(nlist_t *list, list_npc_t *node)
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

unsigned int list_add_npc(nlist_t *list, sfSprite *sprite,
sfVector2f coords, char *text)
{
    list_npc_t *node;

    node = malloc(sizeof(list_npc_t));
    node->npc = sprite;
    node->coords = coords;
    node->npc_text = text;
    node->rect = create_rect(node->rect, 32);
    node->rect.left = 64;
    node->next = NULL;
    node->prev = NULL;
    return list_add_npc_node(list, node);
}
