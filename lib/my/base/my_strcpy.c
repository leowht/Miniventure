/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int y = 0;

    for (; src[y] != '\0'; y++)
        dest[y] = src[y];
    dest[y] = '\0';
    return dest;
}
