/*
** EPITECH PROJECT, 2023
** is_moving
** File description:
** checks if the player is pressing keys to move or not
*/

#include "my.h"

bool is_moving(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (KP(sfKeyRight) || KP(sfKeyLeft) || KP(sfKeyUp) || KP(sfKeyDown))
            return true;
    }
    return false;
}
