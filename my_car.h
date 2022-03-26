#ifndef MY_CAR_H_INCLUDED
#define MY_CAR_H_INCLUDED

typedef struct t_car a_car;

a_car *add_car(char *my_znacka, unsigned short int my_rok_vyroby);
void   show_car(a_car *car);

#endif // MY_CAR_H_INCLUDED
