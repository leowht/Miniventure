/*
** EPITECH PROJECT, 2023
** create_combat
** File description:
** creates combat scene
*/

#include "my.h"

sfBool is_clicked(button_t button, sfMouseButtonEvent* event)
{
    sfFloatRect size = sfRectangleShape_getGlobalBounds(button.rect);
    if (((event->x / 2) >= size.left &&
    (event->x / 2) <= (size.left + size.width)) &&
    ((event->y / 2) + 20) >= size.top &&
    ((event->y / 2) + 20) <= (size.top + size.height))
        return sfTrue;
    return sfFalse;
}

sfBool is_hover(button_t button, sfMouseMoveEvent* event)
{
    sfFloatRect size = sfRectangleShape_getGlobalBounds(button.rect);
    if (((event->x / 2) >= size.left &&
    (event->x / 2) <= (size.left + size.width)) &&
    ((event->y / 2) + 20) >= size.top &&
    ((event->y / 2) + 20) <= (size.top + size.height))
        return sfTrue;
    return sfFalse;
}

static sfRectangleShape *init_rectangle(sfVector2f position, sfVector2f size)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, size);
    return rect;
}

button_t create_button(sfVector2f position, sfVector2f size, char *text)
{
    button_t button;
    sfFloatRect size_b;

    button.button = sfSprite_create();
    sfSprite_setPosition(button.button,
    (sfVector2f){position.x - 28, position.y - 30});
    button.text = sfSprite_create();
    button.text_t = sfTexture_createFromFile(text, NULL);
    sfSprite_setTexture(button.text, button.text_t, sfTrue);
    sfSprite_setScale(button.text, (sfVector2f){0.3, 0.3});
    button.rect = init_rectangle(position, size);
    size_b = sfRectangleShape_getGlobalBounds(button.rect);
    sfSprite_setPosition(button.text,
    (sfVector2f){position.x + (size_b.width / 8),
    position.y + (size_b.height / 3)});
    button.is_clicked = &is_clicked;
    button.is_hover = &is_hover;
    return button;
}

combat_t create_combat(combat_t combat)
{
    combat.back_tex = sfTexture_createFromFile("assets/combat.png", NULL);
    combat.back = sfSprite_create();
    sfSprite_setTexture(combat.back, combat.back_tex, sfFalse);
    combat.is_combat = false;
    combat.b_none = sfTexture_createFromFile("assets/Combat/none.png", NULL);
    combat.b_hover = sfTexture_createFromFile("assets/Combat/hover.png", NULL);
    combat.b_pressed = sfTexture_createFromFile("assets/Combat/pressed.png",
    NULL);
    combat.fight = create_button((sfVector2f){75, 400}, (sfVector2f){345, 100},
"assets/Combat/Fight_text.png");
    combat.shield = create_button((sfVector2f){540, 400},
    (sfVector2f){345, 100}, "assets/Combat/Shield_text.png");
    sfSprite_setTexture(combat.fight.button, combat.b_none, sfTrue);
    sfSprite_setTexture(combat.shield.button, combat.b_none, sfTrue);
    combat.player_turn = true;
    combat.mob = NULL;
    return combat;
}
