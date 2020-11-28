#include <stdio.h>
#include <stdlib.h>
#include "stadt.h"
#include "region.h"

// I guess this is the standard way to do it as i have
// found this in the example program but also on the internet.
// i pretty much copied that and adjusted it.
StadtList *newStadtList()
{
    printf("executed newstadtlist");
    StadtList *sl = (StadtList *)malloc(sizeof(StadtList));
    sl->count = 0;
    sl->allocated = 10;
    sl->stadt = (Stadt **)calloc(sl->allocated, sizeof(Stadt *));
    return sl;
}

// Same as above.
Stadt *newStadt(StadtList *sl)
{
    if (sl->count >= sl->allocated)
    {
        sl->allocated *= 2;
        sl->stadt = (Stadt **)realloc(sl->stadt, sl->allocated * sizeof(Stadt *));
    }
    Stadt *s = (Stadt *)malloc(sizeof(Stadt));
    sl->stadt[sl->count++] = s;
    return s;
}

// Reads the file stadt.dat and adds the data to our StadtList struct.
void readStadtList(StadtList *sl, char *fileName)
{

    FILE *file = fopen(fileName, "r");
    // If there isn't a file, we can't read anything. Return error.
    if (file == NULL)
    {
        perror(fileName);
        exit(1);
    }

    // Integer used for the iteration.
    int r;
    // while r != EOF
    while (r != EOF)
    {

        Stadt *s = newStadt(sl);
        r = fscanf(file, "%d %100s %d %d %d",
                   &s->stadtId, s->name, &s->gebietId, &s->einwohner, &s->meeresHoehe);
        //printStadt(s);
    }

    fclose(file);
}

Stadt *findStadt(StadtList *sl, int id)
{
    int i;
    Stadt *s = NULL;

    for (i = 0; i < sl->count; i++)
        if (sl->stadt[i]->stadtId == id)
        {
            s = sl->stadt[i];
        }
    return s;
}

void TheDestroyer(StadtList *sl, RegionList *rl, int id)
{
    int i;
    int z;
    Region *r = NULL;
    Stadt *s = findStadt(sl, id);

    printf("%101s %s",
           "the city we want to destroy is.......",
           s->name);
}

void printStadt(Stadt *s)
{
    printf("%d %101s %d %d %d \n", s->stadtId, s->name, s->einwohner, s->gebietId, s->meeresHoehe);

    //findStadt(StadtList *sl, 1);
}

void printStadtWithId(StadtList *sl, int id)
{

    //Stadt *s = findStadt(sl, id);

    //printStadt(s);
}

void GetPopulationSize(StadtList *sl, int id)
{

    Stadt *s = findStadt(sl, id);

    printf("%100s, %d", "You requested the population size, here is it:", s->gebietId);
}

void stringSubst(char *s, char old, char new)
{
    while (*s)
    {
        if (*s == old)
            *s = new;
        s++;
    }
}