/*
** EPITECH PROJECT, 2023
** create_inventory
** File description:
** creates and fills the inventory structure
*/

#include "my.h"

inventory_t create_inventory(inventory_t inv)
{
    inv.is_open = false;
    inv.inv = sfSprite_create();
    inv.inv_text = sfTexture_createFromFile("assets/inventory_test.png", NULL);
    sfSprite_setTexture(inv.inv, inv.inv_text, sfTrue);
    sfSprite_setScale(inv.inv, (sfVector2f){0.5, 0.5});
    return inv;
}

void create_objects(list_t *object_list)
{
    list_add(object_list,
    sfTexture_createFromFile("assets/objects_icon/sword_wood.png", NULL));
}
