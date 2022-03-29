#include "stdio.h"
#include "stdlib.h"

typedef struct t_car
{
    char              *znacka;
    unsigned short int rok_vyroby;
} a_car;

a_car *add_car(char *my_znacka, unsigned short int my_rok_vyroby)
{
    a_car *car = malloc(sizeof(a_car));
    *car = (a_car) { my_znacka, my_rok_vyroby };

    return car;
}

void show_car(a_car *car)
{
    printf("Auto: znacka - %16s, rok_vyroby - %5d\n", car -> znacka, car -> rok_vyroby);
}
