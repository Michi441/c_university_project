#ifndef STADT_H
#define STADT_H
#include "region.h"


typedef struct{
    int stadtId;
    char name[101];
    int einwohner;
    int gebietId;
    int meeresHoehe;
} Stadt;


typedef struct {
    Stadt **stadt;
    int count;
    int allocated;
} StadtList;

StadtList *newStadtList();
Stadt *newStadt(StadtList *sl);

void readStadtList(StadtList *sl, char *fileName);
void printStadt(Stadt *s);

// Use this with cautions. Simulated destroyer for a city!
void TheDestroyer(StadtList *sl, RegionList *rl, int id);

void printStadtWithId(StadtList *sl, int id);
void GetPopulationSize(StadtList *sl, int id);

void stringSubst(char *s, char old, char _new); // geh�rt eigtl. nicht hierher

#endif