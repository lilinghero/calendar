#ifndef LINELIST_H
#define LINELIST_H
#include "List.h"
class LineList:public List
{
public:
  // LineList();
    int listEmpty(int* firstAddress);
    int listLength(int* firstAddress);
    int priorElem(int* firstAddress,int number);
    int nextElem(int* firstAddress,int number);
    int getElem(int* firstAddress,int number);
    void locateElem(int* firstAddress,int targetElem);

    void clearList(int* firstAddress);
    void putElem(int* firstAddress,int newElem);
    void listInsert(int* firstAddress,int number,int newElem);
    void listDelete(int* firstAddress,int number);
     /*~LineList(){

    }*/

    int locate[12];/*with 12 or without 12 , can chang the address of  indicator 'this'*/
};

#endif // LINELIST_H
