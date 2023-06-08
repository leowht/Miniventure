/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include "my.h"

static int nb_occ(char const *str, char c)
{
    int total = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c || str[i] == '\n')
            total += 1;
    }
    if (c != ' ')
        total += 1;
    return total;
}

static char *put_in_array(char const *str, int start, int end)
{
    int len = (end - start) + 2;
    char *line = malloc(sizeof(char) * (len + 1));
    int i = 0;
    for (; start <= end; i++) {
        line[i] = str[start];
        start++;
    }
    if (str[end] == '\0')
        line[len - 1] = '\0';
    else if (str[end + 1] == '\n') {
        line[len - 1] = '\n';
        line[len] = '\0';
    } else
        line[len - 1] = '\0';
    return line;
}

char **my_str_to_word_array(char *str, char delim)
{
    int start = 0;
    int end = 0;
    int len = my_strlen(str);
    int nb_occu = nb_occ(str, delim);
    char **split_str = malloc(sizeof(char *) * nb_occu + sizeof(NULL) * 1);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if ((str[i] == delim && str[i + 1] != delim) || str[i] == '\n') {
            end = i - 1;
            split_str[count] = put_in_array(str, start, end);
            start = i + 1;
            count += 1;
        }
    }
    if ((start > end && start != len) || start == 0) {
        split_str[count] = put_in_array(str, start, len);
        count += 1;
    }
    split_str[count] = NULL;
    return split_str;
}
