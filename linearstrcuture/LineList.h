#ifndef LINELIST_H
#define LINELIST_H
#include "List.h"
class LineList:public List
{
public:
  // LineList();
    int listEmpty(void* firstAddress);
    int listLength(void* firstAddress);
    int priorElem(void* firstAddress,int number);
    int nextElem(void* firstAddress,int number);
    int getElem(void* firstAddress,int number);
    void locateElem(void* firstAddress,int targetElem);

    void clearList(void* firstAddress);
    void putElem(void* firstAddress,int newElem);
    void listInsert(void* firstAddress,int number,int newElem);
    void listDelete(void* firstAddress,int number);
     /*~LineList(){

    }*/

    int locate[20];/*with 12 or without 12 , can chang the address of  indicator 'this'*/
};

#endif // LINELIST_H
