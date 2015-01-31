#ifndef SORTING_H
#define SORTING_H
#include "ChainList.h"
#include "LineList.h"
class Sorting
{
public:
    void normalSoting(int *firstAddress);
    void normalSoting(ChainList::numChain *firstAddress);

    void bubbleSoting(int *firstAddress);
    void bubbleSoting(ChainList::numChain *firstAddress);


    List* p;
    ChainList   chainObject;
    LineList      lineObject;
};

#endif // SORTING_H
