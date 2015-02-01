#include "Note.h"
#include <iostream>



Note::Note(){
    this->pHeadDate=&this->headDate;
    this->pHeadSimpMsg=&this->headSimpMsg;
}


void Note::putElem(int year, int month, int day, int numberMsgList){
    Date* date;
    SimpleMsg* msg;

    if(!this->pHeadDate->locateListDate(this->pHeadDate,year,month,day) && !this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList)){

        date=this->pHeadDate->newDateElem(date,this->pHeadDate,year,month,day);
        msg=this->pHeadSimpMsg->newSimpleMsgElem(msg,this->pHeadSimpMsg,numberMsgList);

        date->SimpleMsgAddress[this->pHeadDate->locateSimpleMsgAddress()]=msg;
        msg->dateAddress[this->pHeadSimpMsg->locateDateAddress()]=date;

    }else if (this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList) && !this->pHeadDate->locateListDate(this->pHeadDate,year,month,day)) {

        date=this->pHeadDate->newDateElem(date,this->pHeadDate,year,month,day,this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList));
        this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList)->dateAddress[this->pHeadSimpMsg->locateDateAddress()]=date;

    }else if (this->pHeadDate->locateListDate(this->pHeadDate,year,month,day) && !this->pHeadSimpMsg->locateListSimpeMsg(this->pHeadSimpMsg,numberMsgList)) {

        msg=this->pHeadSimpMsg->newSimpleMsgElem(msg,this->pHeadSimpMsg,numberMsgList,this->pHeadDate->locateListDate(this->pHeadDate,year,month,day));
        this->pHeadDate->locateListDate(this->pHeadDate,year,month,day)->SimpleMsgAddress[this->pHeadDate->locateSimpleMsgAddress()]=msg;

    }else if(this->pHeadDate->locateListDate(date,year,month,day) && this->pHeadSimpMsg->locateListSimpeMsg(msg,numberMsgList)){

        cout<<"you don't need this set! Becaurse you had it setted befor"<<endl;

    }
}

void Note::deleElem(int year, int month, int day){
    SimpleMsg *msgAddress=reinterpret_cast<SimpleMsg*>(this->pHeadDate->getSimpleMsgAddress(this->pHeadDate,year,month,day));
    Date* deletAddress=this->pHeadDate->locateListDate(this->pHeadDate,year,month,day);

    for(int i=0;i < this->pHeadDate->locateSimpleMsgAddress();i++){

    }


}


