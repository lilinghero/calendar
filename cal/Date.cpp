#include "Date.h"
#include <iostream>
using namespace std;


Date::Date(){
    this->nextp=NULL;
    this->SimpleMsgAddress[5]={0};
}





int Date::emptyListDate(Date* firstAddress){
    if(firstAddress == NULL){
        return 0;
    }else{
        return 1;
    }
}

Date* Date::visitListDate(Date* firstAddress){
    if(firstAddress->nextp){
        return firstAddress;
    }else{
        return this->visitListDate(firstAddress->nextp);
    }
}

int Date::lengthList(Date *firstAddress){
    int counter;
    if(this->emptyListDate(firstAddress)){
        for(counter=0;firstAddress->nextp != NULL;counter++){
            firstAddress= firstAddress->nextp;
        }
        return counter-1;
    }
}






Date* Date::locateListDate(Date* firstAddress,int year, int month, int day){
    if(firstAddress->day == day && firstAddress->month == month && firstAddress->year == year){
        return firstAddress;
    }else if ((firstAddress->day != day || firstAddress->month != month || firstAddress->year == year) && firstAddress->nextp == NULL) {
        return NULL;
    }
    else{
        return this->locateListDate(firstAddress->nextp,year,month,day);
    }
}

Date* Date::locatePriorListDate(Date *firstAddress, int year, int month, int day){
    if(firstAddress->nextp->day == day && firstAddress->nextp->month == month && firstAddress->nextp->year == year){
        return firstAddress;
    }else if ((firstAddress->nextp->day != day || firstAddress->nextp->month != month || firstAddress->nextp->year == year) && firstAddress->nextp->nextp == NULL) {
        return NULL;
    }
    else{
        return this->locateListDate(firstAddress->nextp,year,month,day);
    }
}






void* Date::getSimpleMsgAddress(Date *firstAddress, int year, int month, int day){
    firstAddress=this->locateListDate(firstAddress,year,month,day);
    return firstAddress->SimpleMsgAddress;
}

int Date::targetSimpleMsgAddress(void *targetAddres){
    for(int i=0;i < 5;i++){
        if(this->SimpleMsgAddress[i] == targetAddres){
            return i;
        }
    }
}

void Date::deleSimpleMsgAddress(int number){
    this->SimpleMsgAddress[number]=0;
    for(int i=number;i < this->locateSimpleMsgAddress();i++){
        if(number < 4){
            this->SimpleMsgAddress[i]=this->SimpleMsgAddress[i+1];
        }
    }
    this->SimpleMsgAddress[4]=0;
}





int Date::locateSimpleMsgAddress(){
    for(int i=0;i < 5;i++){
        if(this->SimpleMsgAddress == 0){
            return i;
        }
    }
}















Date* Date::newDateElem(Date *firstAddress, Date *headAddress, int year, int month, int day){
    firstAddress=new Date;
    Date* pLastDate=this->visitListDate(headAddress);
    pLastDate->nextp=firstAddress;
    firstAddress->year=year;
    firstAddress->month=month;
    firstAddress->day=day;
    return firstAddress;
}

Date* Date::newDateElem(Date *firstAddress,Date* headAddress,int year, int month, int day, void *addressMsg){
    firstAddress=this->newDateElem(firstAddress,headAddress,year,month,day);
    firstAddress->SimpleMsgAddress[this->locateSimpleMsgAddress()]=addressMsg;
    return firstAddress;
}

void Date::deleDateElem(Date* firstAddress,int year, int month, int day){
    firstAddress=this->locatePriorListDate(firstAddress,year,month,day);
    if(firstAddress->nextp->nextp == NULL){
        delete firstAddress->nextp;
        firstAddress->nextp=NULL;
    }else{
        Date* vessel=firstAddress->nextp->nextp;
        delete firstAddress->nextp;
        firstAddress->nextp=vessel;
    }
}
