#include "stdio.h"
#include "stdlib.h"
#include "my_rec.h"
#include "my_car.h"

int main()
{
    add_rec( "pavelek", 325.0, 18.1);
    add_rec( "novak", 1223.0, 72.5);
    add_rec( "oliva", 13.4, 3.1);
    all_rec();

    del_rec( 1); // delete novak
    all_rec(); // print pavelek and oliva
    getchar();

    del_rec( 0); // delete pavelek
    del_rec( 0); // delete oliva

    a_car *car[20];
    int n;

    car[0] = add_car( "skoda fabia", 2003);
    car[1] = add_car( "honda civic", 2005);
    car[2] = add_car( "porsche carrera", 2004);

    for (n=0;n<3;n++) show_car( car[n]);
    getchar();

    for (n=0;n<3;n++) free( car[n]);

    return 0;
}
