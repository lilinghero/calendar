#ifndef LIST_H
#define LIST_H
class List
{
public:

    virtual int listEmpty(void* firstAddress)=0;
    virtual int listLength(void* firstAddress)=0;
    virtual int priorElem(void* firstAddress,int number)=0;
    virtual int nextElem(void* firstAddress,int number)=0;
    virtual int getElem(void* firstAddress,int number)=0;
    virtual void locateElem(void* firstAddress,int targetElem)=0;

    virtual void clearList(void* firstAddress)=0;
    virtual void putElem(void* firstAddress,int newElem)=0;
    virtual void listInsert(void* firstAddress,int number,int newElem)=0;
    virtual void listDelete(void* firstAddress,int number)=0;

    virtual void replaceElem(void* firstAddress,int number,int replacedValue)=0;
    virtual void  swapElem(void* firstAddress,int positionA,int positionB)=0;


};
#endif // LIST_H
