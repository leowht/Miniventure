/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_str_dup(char *str)
{
    int i = 0;
    char *dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}
