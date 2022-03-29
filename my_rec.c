#include "stdio.h"
#include "stdlib.h"

typedef struct  t_rec  // zaznam
{
    char  *name;    // jmeno ridice
    double km;      // delka jizdy [km]
    double fuel;    // spotreba paliva [l]
} a_rec;

a_rec *records[20];        // karta jizd na 20 zaznamu
int pocet_zaznamu = 0;  // pocet zaznamu v karte

// +++ pridani zaznamu do karty
void add_rec(char *my_name, double my_km, double my_fuel)
{
    records[pocet_zaznamu] =  malloc(sizeof(a_rec));
    *records[pocet_zaznamu] = (a_rec) { my_name, my_km, my_fuel };

    pocet_zaznamu++;
}

// +++ smazani i-teho zaznamu z karty
void del_rec(int ptr)
{
    free(records[ptr]);

    for(int i = ptr; i < pocet_zaznamu; i++)
        records[i] = records[i + 1];

    pocet_zaznamu--;
}

// +++ vypis vsech zaznamu z karty
void all_rec()
{
    printf("Výpis z karty jízd:\n\n");

    if(pocet_zaznamu)
        for(int i = 0; i < pocet_zaznamu; i++)
            printf("Jizda: jmeno - %8s, km - %7.1f, spotreba - %5.1f\n", records[i] -> name, records[i] -> km, records[i] -> fuel);
    else
        printf("Nebyly nalazene zadne zaznamy.");

    printf("\n");
}
