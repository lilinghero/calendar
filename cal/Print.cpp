#include "Print.h"
#include <iostream>


void Print::showMsg(Note* pNote,Date *firstAddress, int year, int month, int day){
    Date* targetDate=firstAddress->locateListDate(firstAddress,year,month,day);
    cout<<"mark date\t"<<year<<" "<<month<<" "<<day<<endl<<"--------------------------------------------"<<endl;
    cout<<firstAddress->locateSimpleMsgAddress(targetDate)<<endl;
    for(int i=0;i < firstAddress->locateSimpleMsgAddress(targetDate);i++){
        SimpleMsg* targetMsg=pNote->getMsgPointer(firstAddress,year,month,day,i);
        cout<<"No."<<i<<"\tis\t"<<targetMsg->siMsg<<endl;
    }
    cout<<"--------------------------------------------"<<endl;
}

void Print::showDate(Note* pNote,SimpleMsg *firstAddress, int numberMsgList){
    SimpleMsg* targetMsg=firstAddress->locateListSimpeMsg(firstAddress,numberMsgList);
    cout<<"mark date\t"<<targetMsg->Msg[numberMsgList]<<endl<<"--------------------------------------------"<<endl;
    for(int i=0;i < firstAddress->locateDateAddress(targetMsg);i++){
        Date* targetDate=pNote->getDatePointer(firstAddress,numberMsgList,i);
        cout<<"No."<<i<<"\tis\t"<<targetDate->year<<" "<<targetDate->month<<" "<<targetDate->day<<endl;
    }
    cout<<"--------------------------------------------"<<endl;
}
