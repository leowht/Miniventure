/*
** EPITECH PROJECT, 2023
** my_int_to_str
** File description:
** transform an int to an str
*/

#include "my.h"

char *my_int_to_str(size_t num)
{
    int	len = 0;
    char *str = NULL;
    int tmp = num;

    if (num == 0)
        return "0\0";
    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = num % 10  + '0';
        num /= 10;
    }
    return (str);
}
