#include "SimpleMsg.h"
#include <iostream>
using namespace std;

const string SimpleMsg::Msg[5]={"Hospital","Dating","Dinner","Meeting","Brithday"};

SimpleMsg::SimpleMsg(){
    this->nextp=NULL;
    this->dateAddress[20]={0};
}




int SimpleMsg::emptyListSimpeMsg(SimpleMsg* firstAddress){
    if(firstAddress == NULL){
        return 0;
    }else{
        return 1;
    }
}

SimpleMsg* SimpleMsg::visitListSimpeMsg(SimpleMsg* firstAddress){
    if(firstAddress->nextp == NULL){
        return firstAddress;
    }else{
        return this->visitListSimpeMsg(firstAddress->nextp);
    }
}

int SimpleMsg::lengthList(SimpleMsg* firstAddress){
    int counter;
    if(this->emptyListSimpeMsg(firstAddress)){
        for(counter=0;firstAddress->nextp != NULL;counter++){
            firstAddress= firstAddress->nextp;
        }
        return counter-1;
    }
}






SimpleMsg* SimpleMsg::locateListSimpeMsg(SimpleMsg* firstAddress,int numberMsgList){
    if(firstAddress->siMsg == this->Msg[numberMsgList]){
        return firstAddress;
    }else if(firstAddress->siMsg != this->Msg[numberMsgList] && firstAddress->nextp) {
        return NULL;
    }else{
        return this->locateListSimpeMsg(firstAddress->nextp,numberMsgList);
    }
}

SimpleMsg* SimpleMsg::locatePriorListSimpeMsg(SimpleMsg *firstAddress, int numberMsgList){
    if(firstAddress->nextp->siMsg == this->Msg[numberMsgList]){
        return firstAddress;
    }else if(firstAddress->nextp->siMsg != this->Msg[numberMsgList] && firstAddress->nextp->nextp == NULL) {
        return NULL;
    }else{
        return this->locateListSimpeMsg(firstAddress->nextp,numberMsgList);
    }
}






void* SimpleMsg::getDateAddress(SimpleMsg *firstAddress, int numberMsgList){
    firstAddress=this->locateListSimpeMsg(firstAddress,numberMsgList);
    return firstAddress->dateAddress;
}

int SimpleMsg::targetDateAddress(void *targetAddress){
    for(int i=0;i < 20;i++){
        if(this->dateAddress[i] == targetAddress){
            return i;
        }
    }
}

void SimpleMsg::deleDateAddress(int number){
    this->dateAddress[number]=0;
    for(int i=number;i < this->locateDateAddress();i++){
        if(number < 19){
            this->dateAddress[i]=this->dateAddress[i+1];
        }
    }
    this->dateAddress[19]=0;
}


int SimpleMsg::locateDateAddress(){
    for(int i=0;i <20 ;i++){
        if(this->dateAddress[i] == 0){
            return i;
        }
    }
}






SimpleMsg* SimpleMsg::newSimpleMsgElem(SimpleMsg *firstAddress, SimpleMsg *headAddress, int numberMsgList){
    firstAddress=new SimpleMsg;
    SimpleMsg* pLastMsg=this->visitListSimpeMsg(headAddress);
    pLastMsg->nextp=firstAddress;
    firstAddress->siMsg=this->Msg[numberMsgList];
    return firstAddress;
}

SimpleMsg* SimpleMsg::newSimpleMsgElem(SimpleMsg *firstAddress,SimpleMsg* headAddress,int numberMsgList, void* addressMsg){
    firstAddress=this->newSimpleMsgElem(firstAddress,headAddress,numberMsgList);
    firstAddress->dateAddress[this->locateDateAddress()]=addressMsg;
    return firstAddress;
}

void SimpleMsg::deleSimpleMsgElem(SimpleMsg *firstAddress, int numberMsgList){
    firstAddress=this->locatePriorListSimpeMsg(firstAddress,numberMsgList);
    if(firstAddress->nextp->nextp == NULL){
        delete firstAddress->nextp;
        firstAddress->nextp=NULL;
    }else{
        SimpleMsg* vessel=firstAddress->nextp->nextp;
        delete firstAddress->nextp;
        firstAddress->nextp=vessel;
    }
}
