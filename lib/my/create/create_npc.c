/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** create_npc.c
*/

#include "my.h"

npc_t create_npc(npc_t npc, sfVector2f coords, char *sheet)
{
    npc.npc = sfSprite_create();
    npc.sheet = sheet;
    npc.coords = coords;
    npc.npc_text = sfTexture_createFromFile(npc.sheet, NULL);
    sfSprite_setTexture(npc.npc, npc.npc_text, sfTrue);
    npc.offset = 32;
    npc.val_max = 128;
    npc.rect = create_rect(npc.rect, npc.offset);
    sfSprite_setTextureRect(npc.npc, npc.rect);
    sfSprite_setPosition(npc.npc, coords);
    return npc;
}
