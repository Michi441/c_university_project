//Michael Lenort
#include <stdio.h>
#include <stdlib.h>
#include "stadt.h"
#include "stadt.c"
// #include "Destroyer.h"
// #include "Destroyer.c"

int main(int argc, char *argv[])
{



    if(argc < 5){

        printf("ya buddy, attention please, the list has less then 5 inputs, i need at least 5 \n");
    }
    StadtList *sl = newStadtList();
    Stadt *newStadt(StadtList *sl);

    readStadtList(sl, argv[1]);

    printStadtWithId(sl, 22);

    GetPopulationSize(sl, 22);
    //DestroyACity(sl, 101);

    return 0;
}