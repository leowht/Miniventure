/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
