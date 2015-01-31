#include <iostream>
#include <string>
#include <iomanip>
#include "List.h"
#include "LineList.h"
#include "ChainList.h"
#include "Sorting.h"
using namespace std;

int main()
{
    List *p;
    LineList  cdd;
    LineList  *app;
    int a[100]={1,8,2,8,7,4,1,1,3,5,8,0};/*without 0*//*a[]anda[100] are diff, when the function put a new member to a[],the program will stop!!*/
    /*p=&cdd;
    cout<<p->listEmpty(a)<<endl;
    cout<<p->listLength(a)<<endl;
    /*p->locateElem(a,8);

    cout<<cdd.locate[0]<<"<--->"<<cdd.locate[1]<<endl<<endl;
    cout<<p->getElem(a,10)<<endl;// the address of p changed ,but why?*the list with no scope chang the address of p
    cout<<p->priorElem(a,10)<<endl;
    cout<<p->nextElem(a,0)<<endl<<endl;
    cout<<p->getElem(a,3)<<endl;p->replaceElem(a,3,6);cout<<p->getElem(a,3)<<endl<<endl;
    p->swapElem(a,3,4);cout<<p->getElem(a,3)<<p->getElem(a,4)<<endl<<endl;

    p->clearList(a);cout<<a[0]<<endl;
    p->putElem(a,8);
    cout<<a[8]<<a[9]<<a[10]<<"<---->"<<a[11]<<"<--->"<<a[12]<<endl;

    p->listDelete(a,11);cout<<a[10]<<endl;
    p->listInsert(a,7,5);cout<<a[7]<<a[8]<<a[9]<<a[10]<<a[11]<<a[12]<<endl;*/

    Sorting testP;
    //testP.normalSoting(a);
    /*testP.bubbleSoting(a);
    cout<<p->listLength(a)<<endl;
    for(int i=0;i<11;i++){
        cout<<a[i]<<endl;
    }*/
    ChainList abba;
    ChainList::numChain*  list;
    p=&abba;

    list=new ChainList::numChain;
    list->member=8;
    list->nextp=NULL;
    for(int i=0;a[i] != 0; i++){
        p->putElem(list,a[i]);
    }
    testP.normalSoting(list);
    //testP.bubbleSoting(list);
    p->clearList(list);


    /*cout<<p->listEmpty(list)<<endl;
    cout<<p->listLength(list)<<endl;

    cout<<p->getElem(list,0)<<"%%%"<<p->getElem(list,6)<<endl;
    p->locateElem(list,4);
    cout<<abba.locate[0]<<endl;
    cout<<p->getElem(list,4)<<endl<<endl;
    cout<<p->priorElem(list,1)<<endl;
    cout<<p->nextElem(list,10)<<endl;
    cout<<p->getElem(list,3)<<endl;p->replaceElem(list,3,6);cout<<p->getElem(list,3)<<endl<<endl;
   p->swapElem(list,3,4);cout<<p->getElem(list,3)<<p->getElem(list,4)<<endl<<endl;
    //p->clearList(list);cout<<p->listLength(list)<<endl;
    p->listDelete(list,3); cout<<p->getElem(list,3)<<endl<<endl;
    p->listInsert(list,3,9);cout<<p->getElem(list,5)<<endl<<endl;*/





}


