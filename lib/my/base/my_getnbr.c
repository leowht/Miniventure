/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** transform a char* into an int
*/

#include "my.h"

size_t my_getnbr(char *str)
{
    int i = 0;
    int sum = 0;
    int neg = 1;

    for (; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            neg *= -1;
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            sum = (sum * 10) + (str[i] - '0');
        else
            return sum * neg;
    }
    return sum * neg;
}
