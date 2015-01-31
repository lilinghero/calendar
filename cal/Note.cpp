#include "Note.h"
#include <iostream>

const string Note::Msg[5]={"Hospital","Dating","Dinner","Meeting","Brithday"};

Note::Note(){
    this->headDate.nextp=NULL;
    this->headSimpMsg.nextp=NULL;
    this->pHeadDate=&this->headDate;
    this->pHeadSimpMsg=&this->headSimpMsg;
}

int Note::emptyListSimpeMsg(){
    if(this->headSimpMsg.nextp == NULL){
        return 0;
    }else{
        return 1;
    }
}

int Note::emptyListDate(){
    if(this->headDate.nextp == NULL){
        return 0;
    }else{
        return 1;
    }
}

Note::SimpleMsg* Note::visitListSimpeMsg(Note::SimpleMsg* firstAddress){
    if(firstAddress->nextp == NULL){
        return firstAddress;
    }else{
        return this->visitListSimpeMsg(firstAddress->nextp);
    }
}

Note::Date* Note::visitListDate(Note::Date* firstAddress){
    if(firstAddress->nextp){
        return firstAddress;
    }else{
        return this->visitListDate(firstAddress->nextp);
    }
}

Note::SimpleMsg* Note::locateListSimpeMsg(Note::SimpleMsg* firstAddress,int numberMsgList){
    if(firstAddress->siMsg == this->Msg[numberMsgList]){
        return firstAddress;
    }else if(firstAddress->siMsg != this->Msg[numberMsgList] && firstAddress->nextp) {
        return NULL;
    }else{
        return this->locateListSimpeMsg(firstAddress->nextp,numberMsgList);
    }
}

Note::Date* Note::locateListDate(Note::Date* firstAddress,int year, int month, int day){
    if(firstAddress->day == day && firstAddress->month == month && firstAddress->year == year){
        return firstAddress;
    }else if ((firstAddress->day != day || firstAddress->month != month || firstAddress->year == year) && firstAddress->nextp == NULL) {
        return NULL;
    }
    else{
        return this->locateListDate(firstAddress->nextp,year,month,day);
    }
}


int Note::lengthList(Note::SimpleMsg *firstAddress){
    int counter=0;
    if(this->emptyListSimpeMsg()){
        while(firstAddress->nextp != NULL){
        counter++;
        firstAddress= firstAddress->nextp;
        }
        return counter-1;
    }else{
        cout<<"this is an empty simpMsgList"<<endl;
    }
}

int Note::lengthList(Note::Date *firstAddress){
    int counter=0;
    if(this->emptyListDate()){
        while(firstAddress->nextp != NULL){
        counter++;
        firstAddress= firstAddress->nextp;
        }
        return counter-1;
    }else{
        cout<<"this is an empty dateList"<<endl;
    }
}


void Note::putElem(int year, int month, int day, int numberMsgList){



    if((!this->locateListDate(date,year,month,day) && !this->locateListSimpeMsg(msg,numberMsgList)) || (!this->emptyListDate() && !this->emptyListSimpeMsg())){
        Date* date=new Date;
        SimpleMsg* msg=new SimpleMsg;

        Note::Date* pLastDate=this->visitListDate(this->pHeadDate);
        Note::SimpleMsg* pLastMsg=this->visitListSimpeMsg(this->pHeadSimpMsg);

        pLastDate->nextp=date;
        date->year=year;
        date->month=month;
        date->day=day;
        date->SimpleMsgAddress[0]=msg;
        date->nextp=NULL;

        pLastMsg->nextp=msg;
        msg->siMsg=this->Msg[numberMsgList];
        msg->dateAddress[0]=date;
        msg->nextp=NULL;


    }else if (this->locateListSimpeMsg(msg,numberMsgList) && !this->locateListDate(date,year,month,day)) {


    }else if (this->locateListDate(date,year,month,day) && !this->locateListSimpeMsg(msg,numberMsgList)) {
        SimpleMsg* msg=new SimpleMsg;
        Note::SimpleMsg* pLastMsg=this->visitListSimpeMsg(this->pHeadSimpMsg);
        Note::Date* date=locateListDate(this->pHeadDate,year,month,day);

        date->year=year;
        date->month=month;
        date->day=day;
        date->SimpleMsgAddress[this->lengthList(this->pHeadSimpMsg)+1]=msg;


        pLastMsg->nextp=msg;
        msg->siMsg=this->Msg[numberMsgList];
        msg->dateAddress[this->lengthList(this->pHeadSimpMsg)+1]=date;
        msg->nextp=NULL;

    }else if(this->locateListDate(date,year,month,day) && this->locateListSimpeMsg(msg,numberMsgList)){

    }
}


