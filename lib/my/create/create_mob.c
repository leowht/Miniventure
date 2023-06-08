/*
** EPITECH PROJECT, 2023
** create_mob
** File description:
** creates and fills mob struct
*/

#include "my.h"

mob_t create_mob(sfVector2f pos, char *text, int max)
{
    mob_t mob;
    mob.mob = sfSprite_create();
    mob.sheet = text;
    mob.mob_text = sfTexture_createFromFile(text, NULL);
    sfSprite_setTexture(mob.mob, mob.mob_text, sfTrue);
    mob.offset = 32;
    mob.val_max = max;
    mob.rect.top = 0;
    mob.rect.left = 32;
    mob.rect.width = mob.offset;
    mob.rect.height = 32;
    sfSprite_setTextureRect(mob.mob, mob.rect);
    sfSprite_setPosition(mob.mob, pos);
    mob.coords = pos;
    srand(time(0));
    mob.hp = (rand() % 6) + 5;
    mob.atk = (rand() % 3) + 1;
    mob.def = (rand() % 2) + 2;
    mob.lck = 1;
    return mob;
}
