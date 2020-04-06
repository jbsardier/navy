/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** put_str
*/

#include <unistd.h>

int my_putstr(char *str)
{
    int nb_char = 0;
    int i = 0;

    if (str == NULL) {
        return (-1);
    }
    while (str[i] != '\0') {
        nb_char = nb_char + write(1, &str[i], 1);
        ++i;
    }
    if (nb_char != i) {
        return (-1);
    }
    return (nb_char);
}

int my_putstr_error(char *str)
{
    int nb_char = 0;
    int i = 0;

    if (str == NULL) {
        return (-1);
    }
    while (str[i] != '\0') {
        nb_char = nb_char + write(2, &str[i], 1);
        ++i;
    }
    if (nb_char != i) {
        return (-1);
    }
    return (nb_char);
}