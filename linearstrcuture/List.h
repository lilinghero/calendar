#ifndef LIST_H
#define LIST_H
class List
{
public:

    virtual int listEmpty(int* firstAddress)=0;
    virtual int listLength(int* firstAddress)=0;
    virtual int priorElem(int* firstAddress,int number)=0;
    virtual int nextElem(int* firstAddress,int number)=0;
    virtual int getElem(int* firstAddress,int number)=0;
    virtual void locateElem(int* firstAddress,int targetElem)=0;

    virtual void clearList(int* firstAddress)=0;
    virtual void putElem(int* firstAddress,int newElem)=0;
    virtual void listInsert(int* firstAddress,int number,int newElem)=0;
    virtual void listDelete(int* firstAddress,int number)=0;

};
#endif // LIST_H
