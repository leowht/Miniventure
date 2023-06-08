/*
** EPITECH PROJECT, 2023
** load_file_in_mem
** File description:
** loads the file in a char *
*/

#include "my.h"

char *load_file_in_mem(char const *filepath)
{
    struct stat buffer;
    int fine = 0;
    int open_file = open(filepath, O_RDONLY);
    int total_size = 0;
    char *loaded_file;

    if (open_file == -1) {
        write(1, "OPEN FAILED\n", 12);
        return NULL;
    }
    fine = stat(filepath, &buffer);
    if (fine != 0)
        return NULL;
    total_size = buffer.st_size;
    loaded_file = malloc(sizeof(char) * (total_size));
    read(open_file, loaded_file, total_size);
    loaded_file[total_size] = '\0';
    close(open_file);
    return loaded_file;
}
