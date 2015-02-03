#include "Note.h"
#include <iostream>



Note::Note(){
    this->pHeadDate=&this->headDate;
    this->pHeadSimpMsg=&this->headSimpMsg;
}


void Note::putElem(int year, int month, int day, int numberMsgList){
    Date* date;
    SimpleMsg* msg;
    Date* targetDateAddress=this->pHeadDate->locateListDate(this->pHeadDate,year,month,day);
    SimpleMsg* targetSimpleMsgAddress=this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList);
    int orderSimpleMsgAddress;
    int orderDateAddress;
    if(targetDateAddress != 0){
        orderSimpleMsgAddress=this->pHeadDate->locateSimpleMsgAddress(targetDateAddress);
    }
    if(targetSimpleMsgAddress != 0){
        orderDateAddress=this->pHeadSimpMsg->locateDateAddress(targetSimpleMsgAddress);
    }
    if(!targetDateAddress && !targetSimpleMsgAddress){
        cout<<"^^123123"<<endl;
        date=this->pHeadDate->newDateElem(this->pHeadDate,year,month,day);
        msg=this->pHeadSimpMsg->newSimpleMsgElem(this->pHeadSimpMsg,numberMsgList);

        date->SimpleMsgAddress[0]=msg;
        msg->dateAddress[0]=date;

    }else if (targetSimpleMsgAddress && !targetDateAddress) {
         cout<<"@123123"<<endl;
        date=this->pHeadDate->newDateElem(this->pHeadDate,year,month,day,targetSimpleMsgAddress);
        targetSimpleMsgAddress->dateAddress[orderDateAddress]=date;
        //cout<<orderDateAddress<<endl;

    }else if (targetDateAddress && !targetSimpleMsgAddress) {
         cout<<"#123123"<<endl;
        msg=this->pHeadSimpMsg->newSimpleMsgElem(this->pHeadSimpMsg,numberMsgList,targetDateAddress);
        targetDateAddress->SimpleMsgAddress[orderSimpleMsgAddress]=msg;
        //cout<<orderDateAddress<<endl;
    }else if(targetDateAddress && targetSimpleMsgAddress){
         cout<<"$123123"<<endl;
        cout<<"you don't need this set! Becaurse you had it setted befor"<<endl;

    }
}

SimpleMsg* Note::getMsgPointer(Date *firstAddress, int year, int month, int day, int numberAddress){
    void * msgDefaultAddress=firstAddress->getSimpleMsgAddress(firstAddress,year,month,day);
    SimpleMsg** msgInitialAddress=reinterpret_cast<SimpleMsg**>(msgDefaultAddress+numberAddress);;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    SimpleMsg* msg=*msgInitialAddress;
    return msg;
}

Date* Note::getDatePointer(SimpleMsg *firstAddress, int numberMsgList, int numberAddress){
    void* dateDefaultAddress=firstAddress->getDateAddress(firstAddress,numberMsgList);
    Date** dateInitialAddress=reinterpret_cast<Date**>(dateDefaultAddress+numberAddress);;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    Date* date=*dateInitialAddress;
    return date;
}

void Note::deleElem(int year, int month, int day){
    Date* targetAddress=this->pHeadDate->locateListDate(this->pHeadDate,year,month,day);
    for(int i=0;i < this->pHeadDate->locateSimpleMsgAddress(targetAddress);i++){
        SimpleMsg* msg=this->getMsgPointer(this->pHeadDate,year,month,day,i);
        this->pHeadSimpMsg->deleDateAddress(this->pHeadSimpMsg,msg,targetAddress);
    }
    this->pHeadDate->deleDateElem(this->pHeadDate,year,month,day);
}

void Note::deleElem(int numberMsgList){
    SimpleMsg* targetAddress=this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList);
    for(int i=0;i < this->pHeadSimpMsg->locateDateAddress(targetAddress);i++){
        Date* date=this->getDatePointer(this->pHeadSimpMsg,numberMsgList,i);
        this->pHeadDate->deleSimpleMsgAddress(this->pHeadDate,date,targetAddress);
    }
    this->pHeadSimpMsg->deleSimpleMsgElem(this->pHeadSimpMsg,numberMsgList);
}

void Note::deleElem(int year, int month, int day, int numberMsgList){
    Date* targetDateAddress=this->pHeadDate->locateListDate(this->pHeadDate,year,month,day);
    SimpleMsg* targetSimpleMsgAddress=this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList);
    int dateNumber=this->pHeadSimpMsg->targetDateAddress(targetSimpleMsgAddress,targetDateAddress);
    int simpleMsgNumber=this->pHeadDate->targetSimpleMsgAddress(targetDateAddress,targetSimpleMsgAddress);
    SimpleMsg* msg=this->getMsgPointer(this->pHeadDate,year,month,day,simpleMsgNumber);
    Date* date=this->getDatePointer(this->pHeadSimpMsg,numberMsgList,dateNumber);
    this->pHeadSimpMsg->deleDateAddress(this->pHeadSimpMsg,msg,targetDateAddress);
    this->pHeadDate->deleSimpleMsgAddress(this->pHeadDate,date,targetSimpleMsgAddress);
}

void Note::clearSingleList(Date *pHeadDate){
    if(pHeadDate->nextp == NULL){
        delete pHeadDate;
    }else {
        this->clearSingleList(pHeadDate->nextp);
        pHeadDate->nextp=NULL;
        delete pHeadDate;
    }
}

void Note::clearSingleList(SimpleMsg *pHeadSimpMsg){
    if(pHeadSimpMsg->nextp == NULL){
        delete pHeadSimpMsg;
    }else {
        this->clearSingleList(pHeadSimpMsg->nextp);
        pHeadSimpMsg->nextp=NULL;
        delete pHeadSimpMsg;
    }
}

void Note::clearAll(){
    this->clearSingleList(this->pHeadDate);
    this->clearSingleList(this->pHeadSimpMsg);
}


