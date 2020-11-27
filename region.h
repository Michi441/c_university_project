#ifndef REGION_H
#define REGION_H
typedef struct
{

    int regionId;
    char name[101];
    int overRegion;
    char typ[1];
  
} Region;

typedef struct
{
    Region **region;
    int count;
    int allocated;
} RegionList;
