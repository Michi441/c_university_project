#include <stdio.h>
#include <stdlib.h>
#include "stadt.h"
#include "stadt.c"
#include "region.h"

RegionList *RegionList()
{
    printf("executed newstadtlist");
    RegionList *rl = (RegionList *)malloc(sizeof(RegionList));
    rl->count = 0;
    rl->allocated = 10;
    rl->region = (Region **)calloc(rl->allocated, sizeof(Region *));
    return rl;
}

// Same as above.
Region *newRegion(RegionList *rl)
{
    if (rl->count >= rl->allocated)
    {
        rl->allocated *= 2;
        rl->region = (Region **)realloc(sl->region, sl->allocated * sizeof(Region *));
    }
    Region *r = (Region *)malloc(sizeof(Region));
    rl->region[rl->count++] = r;
    return r;
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
