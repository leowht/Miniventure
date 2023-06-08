/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(char *str, char *cmp, int lim)
{
    int i = 0;

    for (; i != lim; i++) {
        if (str[i] == '\0' || cmp[i] == '\0')
            return 1;
        if (str[i] != cmp[i])
            return 1;
    }
    return 0;
}
