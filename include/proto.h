/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "my.h"

//put_str.c
int my_putstr(char *);
int my_putstr_error(char *);

//my_getnbr.c
int where_num(char const *);
int negat(int, char const *);
int my_getnbr(char const *);

//navy.c
int navy(int , char *);
int player_game(int );
int pid_game(int, int );

//my_getnbr_base.c
int my_strlen(char *);
int base_to_int(char const *, char);
int my_getnbr_base(char const *, char *);

//my_put_nbr
int my_put_nbr(int );
void my_putchar(char );

//signal
int recep_connection(int );
void handler_sig2(int );
void handler_sig1(int );
void ini_signal(void);
int send_sign(int, int, int);

//map.c
char **fill_tab(char **);
char **creat_tab(void);
char **read_map(char *);
int modif_map_ennemi(char **, int, int, int);
int modif_map(char **, int);

//display
char **fill_up(char **, char *);
char **fill_line(char **, char *);
char **fill_map(char **, char *);
int print_map(char **);

//win_or_lose.c
int win_or_lose(char **, char **);
int win(char **);
int lose(char **);


char *dec_to_bin(int nbr, int size);
int connection_player_one(int *pid_ennemi, int pid, int nbr);
int connection_player_two(int *pid_ennemi, int pid, int nbr);
coord_t get_input(void);
int game_player_1(int pid_ennemi, char **map);
int game_player_2(int pid_ennemi, char **map);
int display(char **map_p1, char **map_p2);

int coord_x(char *str);
int coord_y(char *str);
int display_result(int res);
int display_error(int ac);

int line_valid(int *boat, char *buf);
int check_str(char *str);

#endif /* !PROTO_H_ */