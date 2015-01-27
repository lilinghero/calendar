#include "List.h"
#include <iostream>
using namespace std;
int List::listEmpty(int *firstAdddress)=0;
int List::listLength(int *firstAdddress)=0;
int List::priorElem(int *firstAdddress, int targetElem)=0;
int List::nextElem(int *firstAdddress, int targetElem)=0;
int List::locateElem(int *firstAdddress, int targetElem)=0;
int List::getElem(int *firstAdddress, int targetElem)=0;

int List::clearList(int *firstAdddress)=0;
int List::putElem(int *firstAdddress, int newElem)=0;
int List::listDelete(int *firstAdddress)=0;
int List::listInsert(int *firstAdddress, int newElem)=0;
