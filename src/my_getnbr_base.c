/*
** EPITECH PROJECT, 2019
** my_getnbr_base
** File description:
** return the nb in the base given
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        ++i;
    }
    return (i);
}

int base_to_int(char const *base, char c)
{
    int i = 0;

    while (base[i] != '\0') {
        if (c == base[i])
            return i;
        i++;
    }
    return i;
}

int my_getnbr_base(char const *str, char *base)
{
    int result = 0;
    int i = 0;
    int tmp = 0;
    int sizebase = my_strlen(base);

    while (str[i] == '0') {
        ++i;
    }
    while (str[i] != '\0') {
        tmp = base_to_int(base, str[i]);
        result = result + tmp;
        if (str[i + 1] != '\0') {
            result = result * sizebase;
        }
        tmp = 0;
        i++;
    }
    return result;
}
