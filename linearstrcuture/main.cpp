#include <iostream>
#include <string>
#include <iomanip>
#include "List.h"
#include "LineList.h"
using namespace std;

int main()
{

    List *p;
    LineList  cdd;
    int a[100]={1,8,2,8,7,4,1,1,3,5,2,0};/*without 0*//*a[]anda[100] are diff, when the function put a new member to a[],the program will stop!!*/
    p=&cdd;

    cout<<p->listEmpty(a)<<endl;
    cout<<p->listLength(a)<<endl;
    p->locateElem(a,8);
    cout<<p->getElem(a,10)<<endl;/* the address of p changed ,but why?*the list with no scope chang the address of p*/
    cout<<p->priorElem(a,10)<<endl;
    cout<<p->nextElem(a,0)<<endl;

    //p->clearList(a);cout<<a[0]<<endl;
    p->putElem(a,8);
    cout<<a[8]<<a[9]<<a[10]<<"<---->"<<a[11]<<"<--->"<<a[12]<<endl;

    p->listDelete(a,11);cout<<a[10]<<endl;
    p->listInsert(a,7,5);cout<<a[7]<<a[8]<<a[9]<<a[10]<<a[11]<<a[12]<<endl;


}


