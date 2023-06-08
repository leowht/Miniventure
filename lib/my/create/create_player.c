/*
** EPITECH PROJECT, 2023
** create_player
** File description:
** creates and fills the player struct
*/

#include "my.h"

sfIntRect create_rect(sfIntRect rect, int offset)
{
    rect.top = 32;
    rect.left = 0;
    rect.width = offset;
    rect.height = 32;
    return rect;
}

player_t create_player(page_t page)
{
    player_t sprite;
    sprite.player = sfSprite_create();
    sprite.map_colliosions = sfTexture_copyToImage(page.coll_tex);
    sprite.sheet = "assets/Sprite/playerSprites_/bandit_.png";
    sprite.player_text = sfTexture_createFromFile(sprite.sheet, NULL);
    sfSprite_setTexture(sprite.player, sprite.player_text, sfTrue);
    sprite.offset = 32;
    sprite.val_max = 128;
    sprite.rect = create_rect(sprite.rect, sprite.offset);
    sfSprite_setTextureRect(sprite.player, sprite.rect);
    sfSprite_setPosition(sprite.player, (sfVector2f){1615, 4800});
    return sprite;
}
