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
    int orderSimpleMsgAddress=this->pHeadDate->locateSimpleMsgAddress(targetDateAddress);
    int orderDateAddress=this->pHeadSimpMsg->locateDateAddress(targetSimpleMsgAddress);

    if(!targetDateAddress && !targetSimpleMsgAddress){

        date=this->pHeadDate->newDateElem(this->pHeadDate,year,month,day);
        msg=this->pHeadSimpMsg->newSimpleMsgElem(this->pHeadSimpMsg,numberMsgList);

        date->SimpleMsgAddress[0]=msg;
        msg->dateAddress[0]=date;

    }else if (targetSimpleMsgAddress && !targetDateAddress) {

        date=this->pHeadDate->newDateElem(this->pHeadDate,year,month,day,targetSimpleMsgAddress);
        targetSimpleMsgAddress->dateAddress[orderDateAddress]=date;

    }else if (targetDateAddress && !targetSimpleMsgAddress) {

        msg=this->pHeadSimpMsg->newSimpleMsgElem(this->pHeadSimpMsg,numberMsgList,targetDateAddress);
        targetDateAddress->SimpleMsgAddress[orderSimpleMsgAddress]=msg;

    }else if(targetDateAddress && targetSimpleMsgAddress){

        cout<<"you don't need this set! Becaurse you had it setted befor"<<endl;

    }
}

SimpleMsg* Note::deleAddress(int year, int month, int day, int number){
    void * msgDefaultAddress=this->pHeadDate->getSimpleMsgAddress(this->pHeadDate,year,month,day);
    Date* targetAddress=this->pHeadDate->locateListDate(this->pHeadDate,year,month,day);
    SimpleMsg** msgInitialAddress=reinterpret_cast<SimpleMsg**>(msgDefaultAddress+number);;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    SimpleMsg* msg=*msgInitialAddress;
    int positionDateAddress=msg->targetDateAddress(msg,targetAddress);
    this->pHeadSimpMsg->deleDateAddress(msg,positionDateAddress);
    return msg;
}

Date* Note::deleAddress(int numberMsgList, int number){
    void* dateDefaultAddress=this->pHeadSimpMsg->getDateAddress(this->pHeadSimpMsg,numberMsgList);
    SimpleMsg* targetAddress=this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList);
    Date** dateInitialAddress=reinterpret_cast<Date**>(dateDefaultAddress+number);;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    Date* date=*dateInitialAddress;
    int positionSimpleMsgAddress=this->pHeadDate->targetSimpleMsgAddress(date,targetAddress);
    this->pHeadDate->deleSimpleMsgAddress(date,positionSimpleMsgAddress);
    return date;
}


void Note::deleElem(int year, int month, int day){
    SimpleMsg* msg;
    Date* deletAddress=this->pHeadDate->locateListDate(this->pHeadDate,year,month,day);
    for(int i=0;i < this->pHeadDate->locateSimpleMsgAddress(deletAddress);i++){
        msg=this->deleAddress(year,month,day,i);
        if(this->pHeadSimpMsg->locateDateAddress(msg) == 0){
            int positionMsg=this->pHeadSimpMsg->getMsgPosition(msg->siMsg);
            this->pHeadSimpMsg->deleSimpleMsgElem(this->pHeadSimpMsg,positionMsg);
        }
    }
    this->pHeadDate->deleDateElem(deletAddress,year,month,day);
}

void Note::deleElem(int numberMsgList){
    Date* date;
    SimpleMsg* deleAddress=this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList);

    for(int i=0;i < this->pHeadSimpMsg->locateDateAddress(deleAddress);i++){
        date=this->deleAddress(numberMsgList,i);
        if(this->pHeadDate->locateSimpleMsgAddress(date) == 0){
            this->pHeadDate->deleDateElem(this->pHeadDate,date->year,date->month,date->day);
        }
    }
    this->pHeadSimpMsg->deleSimpleMsgElem(this->pHeadSimpMsg,numberMsgList);
}

void Note::deleElem(int year, int month, int day, int numberMsgList){
    Date* targetDateAddress=this->pHeadDate->locateListDate(this->pHeadDate,year,month,day);
    SimpleMsg* targetSimpleMsgAddress=this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList);
    int dateNumber=this->pHeadSimpMsg->targetDateAddress(targetSimpleMsgAddress,targetDateAddress);
    int simpleMsgNumber=this->pHeadDate->targetSimpleMsgAddress(targetDateAddress,targetSimpleMsgAddress);
    this->deleAddress(year,month,day,simpleMsgNumber);
    this->deleAddress(numberMsgList,dateNumber);
    if(this->pHeadSimpMsg->locateDateAddress(targetSimpleMsgAddress) == 0){
        int positionMsg=this->pHeadSimpMsg->getMsgPosition(targetSimpleMsgAddress->siMsg);
        this->pHeadSimpMsg->deleSimpleMsgElem(this->pHeadSimpMsg,positionMsg);
    }
    if(this->pHeadDate->locateSimpleMsgAddress(targetDateAddress) == 0){
        this->pHeadDate->deleDateElem(this->pHeadDate,targetDateAddress->year,targetDateAddress->month,targetDateAddress->day);
    }
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


