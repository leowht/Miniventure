/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thibaud.le-creurer
** File description:
** create_texte.c
*/

#include "my.h"

all_t destroy_npc_texte(all_t all)
{
    sfRectangleShape_destroy(all.npc_text.bulle);
    sfFont_destroy(all.npc_text.font);
    sfText_destroy(all.npc_text.text);
    return all;
}

all_t create_npc_texte(all_t all,sfSprite *npc, char* chat)
{
    all.npc_text.bulle = sfRectangleShape_create();
    sfFloatRect npcBounds = sfSprite_getGlobalBounds(npc);
    sfVector2f bullePos = {npcBounds.left + npcBounds.width,
    npcBounds.top - 60};
    sfVector2f textPos = {bullePos.x + 10, bullePos.y + 10};
    all.npc_text.font = sfFont_createFromFile("assets/Font/font.ttf");
    all.npc_text.text = sfText_create();
    sfRectangleShape_setSize(all.npc_text.bulle,
    (sfVector2f){my_strlen(chat) * 15, 50});
    sfRectangleShape_setFillColor(all.npc_text.bulle, sfWhite);
    sfRectangleShape_setOutlineThickness(all.npc_text.bulle, 2);
    sfRectangleShape_setOutlineColor(all.npc_text.bulle, sfBlack);
    sfRectangleShape_setPosition(all.npc_text.bulle, bullePos);
    sfText_setString(all.npc_text.text, chat);
    sfText_setFont(all.npc_text.text, all.npc_text.font);
    sfText_setCharacterSize(all.npc_text.text, 14);
    sfText_setFillColor(all.npc_text.text, sfBlack);
    sfText_setPosition(all.npc_text.text, textPos);
    return all;
}
