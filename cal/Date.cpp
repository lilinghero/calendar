#include "Date.h"
#include <iostream>
using namespace std;


Date::Date(){
    this->nextp=NULL;
    for(int i=0;i < 5;i++){
        this->SimpleMsgAddress[i]=NULL;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
      }
}



//================================
int Date::emptyListDate(Date* firstAddress){
    if(firstAddress == NULL){
        return 0;
    }else{
        return 1;
    }
}

Date* Date::visitListDate(Date* firstAddress){
    if(firstAddress->nextp == NULL){
        return firstAddress;
    }else{
        return this->visitListDate(firstAddress->nextp);
    }
}

int Date::lengthList(Date *firstAddress){
    int counter;
    Date* address=firstAddress;

    if(this->emptyListDate(firstAddress)){
        for(counter=0;address->nextp != NULL;counter++){
            address=address->nextp;
        }
        return counter-1;
    }
}



//================================
Date* Date::locateListDate(Date* firstAddress,int year, int month, int day){
    if(firstAddress->day == day && firstAddress->month == month && firstAddress->year == year){
        return firstAddress;
    }else if ((firstAddress->day != day || firstAddress->month != month || firstAddress->year == year) && firstAddress->nextp == NULL) {
        return NULL;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1*/
    }
    else{
        return this->locateListDate(firstAddress->nextp,year,month,day);
    }
}

Date* Date::locatePriorListDate(Date *firstAddress, int year, int month, int day){
    if(firstAddress->nextp->day == day && firstAddress->nextp->month == month && firstAddress->nextp->year == year){
        return firstAddress;
    }else if ((firstAddress->nextp->day != day || firstAddress->nextp->month != month || firstAddress->nextp->year == year) && firstAddress->nextp->nextp == NULL) {
        return NULL;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    }
    else{
        return this->locateListDate(firstAddress->nextp,year,month,day);
    }
}



//================================
void* Date::getSimpleMsgAddress(Date *firstAddress, int year, int month, int day){
    Date* targetAddress=this->locateListDate(firstAddress,year,month,day);
    return targetAddress->SimpleMsgAddress;
}

//================================
int Date::targetSimpleMsgAddress(Date *targetAddress, void *msgAddress){
    for(int i=0;i < this->locateSimpleMsgAddress(targetAddress);i++){
        if(targetAddress->SimpleMsgAddress[i] == msgAddress){
            return i;
        }
    }
}

void Date::deleSimpleMsgAddress(Date* firstAddress,Date* targetAddress,void *msgAddress){
    int number=this->targetSimpleMsgAddress(targetAddress,msgAddress);

    targetAddress->SimpleMsgAddress[number]=0;
    for(int i=number;i < this->locateSimpleMsgAddress(targetAddress);i++){
        if(number < 4){
            targetAddress->SimpleMsgAddress[i]=targetAddress->SimpleMsgAddress[i+1];
        }
    }
    targetAddress->SimpleMsgAddress[4]=0;
    if(this->locateSimpleMsgAddress(targetAddress) == 0){
        this->deleDateElem(firstAddress,targetAddress->year,targetAddress->month,targetAddress->day);
    }
}

int Date::locateSimpleMsgAddress(Date* targetAddress){
     //cout<<targetAddress->SimpleMsgAddress[3]<<endl;
    for(int i=0;i < 5;i++){
        //cout<<targetAddress->SimpleMsgAddress[i]<<"%%%"<<i<<endl;
        if(targetAddress->SimpleMsgAddress[i] == 0){
//cout<<"((()))"<<endl;
            return i;
        }

    }
}



//================================
Date* Date::newDateElem(Date *firstAddress, int year, int month, int day){

    Date* targetAddress=new Date;
    Date* pLastDate=this->visitListDate(firstAddress);
    pLastDate->nextp=targetAddress;
    targetAddress->year=year;
    targetAddress->month=month;
    targetAddress->day=day;

    return targetAddress;


}

Date* Date::newDateElem(Date* firstAddress,int year, int month, int day, void *addressMsg){
    Date* targetAddress=this->newDateElem(firstAddress,year,month,day);
    targetAddress->SimpleMsgAddress[this->locateSimpleMsgAddress(targetAddress)]=addressMsg;
    return targetAddress;
}

void Date::deleDateElem(Date* firstAddress,int year, int month, int day){
    Date* targetAddress=this->locatePriorListDate(firstAddress,year,month,day);
    if(targetAddress->nextp->nextp == NULL){
        delete targetAddress->nextp;
        targetAddress->nextp=NULL;
    }else{
        Date* vessel=targetAddress->nextp->nextp;
        delete targetAddress->nextp;
        targetAddress->nextp=vessel;
    }
}
