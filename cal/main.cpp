#include <iostream>
//#include <string>
#include <iomanip>
#include "Calculate.h"
#include "Ui.h"
#include "Note.h"
#include "Print.h"
using namespace std;



int main()
{
    /*Ui putMsg;
    Calculate calMethod;
    int year,month,day;
    cin>>year>>month>>day;
    putMsg.pringMessage(year,month,calMethod.lenghMonth(year,month),calMethod.recursiveFirstDate(year,month),day);*/

    Note note;
    Note* pNote=&note;
    Print p;

    string Msg[5]={"Hospital","Dating","Dinner","Meeting","Brithday"};
    int year[20]={2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015,2015};
    int month[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int day[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    //Date* i=pNote->pHeadDate->locateListDate(pNote->pHeadDate,1,1,1);
    //note.putElem(year[0],month[0],day[0],0);
    //p.showMsg(pNote,pNote->pHeadDate,year[0],month[0],day[0]);
    //p.showMsg(pNote,pNote->pHeadDate,year[0],month[0],day[0]);
    for(int i=0;i < 1;i++){
        for(int k=0;k < 3;k++){
            note.putElem(year[i],month[i],day[i],k);
        }
    }

    for(int i=0;i < 1;i++){
        p.showMsg(pNote,pNote->pHeadDate,year[i],month[i],day[i]);
    }








}























