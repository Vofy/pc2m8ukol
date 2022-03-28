#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct  t_rec  // zaznam
{
    char   *name;    // jmeno ridice
    double *km;      // delka jizdy [km]
    double *fuel;    // spotreba paliva [l]
} a_rec;

a_rec karta[20];        // karta jizd na 20 zaznamu
int pocet_zaznamu = 0;  // pocet zaznamu v karte

// +++ pridani zaznamu do karty
void add_rec(char *my_name, double my_km, double my_fuel)
{
    char   *name = malloc(strlen(my_name));
    double *km   = malloc(sizeof my_km);
    double *fuel = malloc(sizeof my_fuel);

    strcpy(name, my_name);
    *km = my_km;
    *fuel = my_fuel;

    karta[pocet_zaznamu++] = (a_rec)
    {
        name, km, fuel
    };
}

// +++ smazani i-teho zaznamu z karty
void del_rec(int ptr)
{
    free(karta[ptr]);

    for(int i = ptr; i < pocet_zaznamu; i++)
        karta[i] = karta[i + 1];

    pocet_zaznamu--;
}

// +++ vypis vsech zaznamu z karty
void all_rec()
{
    printf("Výpis z karty jízd:\n\n");

    if(pocet_zaznamu)
        for(int i = 0; i < pocet_zaznamu; i++)
            printf("Jmého: %8s, km: %7.1f, fuel: %5.1f\n", karta[i].name, *(karta[i].km), *(karta[i].fuel));
    else
        printf("Nebyly nalazene zadne zaznamy.");

    printf("\n");
}
