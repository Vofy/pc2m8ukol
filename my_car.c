#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct t_car
{
    char *znacka;
    unsigned short int *rok_vyroby;
} a_car;

a_car auta[20];
int pocet_aut = 0;

a_car *add_car(char *my_znacka, unsigned short int my_rok_vyroby)
{
    char *znacka = malloc(strlen(my_znacka) * sizeof(char));
    unsigned short int *rok_vyroby = malloc(sizeof my_rok_vyroby);

    strcpy(znacka, my_znacka);
    *rok_vyroby = my_rok_vyroby;

    auta[pocet_aut] = (a_car) { znacka, rok_vyroby };

    return &auta[pocet_aut++];
}

void del_car(int ptr)
{
    free(auta[ptr].znacka);
    free(auta[ptr].rok_vyroby);

    for(int i = ptr; i < pocet_aut; i++)
    {
        auta[i] = auta[i + 1];
    }

    pocet_aut--;
}

void all_cars(void)
{
    printf("Všechna auta:\n\n");

    if(pocet_aut)
        for(int i = 0; i < pocet_aut; i++)
            printf("Znacka: %16s, rok_vyroby: %5d\n", auta[i].znacka, *(auta[i].rok_vyroby));
    else
        printf("Nebyly nalazene zadne zaznamy");

    printf("\n");
}

void show_car(a_car *car)
{
    printf("Znacka: %16s, rok_vyroby: %5d\n", car -> znacka, *(car -> rok_vyroby));
}
