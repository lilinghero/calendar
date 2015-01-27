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
    virtual int locateElem(int* firstAddress,int targetElem)=0;
    //virtual  int listTraverse()=0;

    virtual void clearList(int* firstAddress)=0;
    virtual void putList(int* firstAdddress,int newElem)=0;
    virtual void listInsert(int* firstAdddress,int number,int newElem)=0;
    virtual void listDelete(int* firstAdddress,int number)=0;

};
#endif // LIST_H
