#include "SimpleMsg.h"
#include <iostream>
using namespace std;

const string SimpleMsg::Msg[5]={"Hospital","Dating","Dinner","Meeting","Brithday"};

SimpleMsg::SimpleMsg(){
    this->nextp=NULL;
    this->dateAddress[20]={0};;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
}



//================================
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
    SimpleMsg* address=firstAddress;
    if(this->emptyListSimpeMsg(firstAddress)){
        for(counter=0;address->nextp != NULL;counter++){
            address= address->nextp;
        }
        return counter-1;
    }
}



//================================
SimpleMsg* SimpleMsg::locateListSimpeMsg(SimpleMsg* firstAddress,int numberMsgList){
    if(firstAddress->siMsg == this->Msg[numberMsgList]){
        return firstAddress;
    }else if(firstAddress->siMsg != this->Msg[numberMsgList] && firstAddress->nextp == NULL) {
        return NULL;;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    }else{
        return this->locateListSimpeMsg(firstAddress->nextp,numberMsgList);
    }
}

SimpleMsg* SimpleMsg::locatePriorListSimpeMsg(SimpleMsg *firstAddress, int numberMsgList){
    if(firstAddress->nextp->siMsg == this->Msg[numberMsgList]){
        return firstAddress;
    }else if(firstAddress->nextp->siMsg != this->Msg[numberMsgList] && firstAddress->nextp->nextp == NULL) {
        return NULL;;/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    }else{
        return this->locateListSimpeMsg(firstAddress->nextp,numberMsgList);
    }
}



//================================
void* SimpleMsg::getDateAddress(SimpleMsg *firstAddress, int numberMsgList){
    SimpleMsg* targetAddress=this->locateListSimpeMsg(firstAddress,numberMsgList);
    return targetAddress->dateAddress;
}

int SimpleMsg::targetDateAddress(SimpleMsg *targetAddress, void *dateAddress){
    for(int i=0;i < this->locateDateAddress(targetAddress);i++){
        if(targetAddress->dateAddress[i] == dateAddress){
            return i;
        }
    }
}

void SimpleMsg::deleDateAddress(SimpleMsg* firstAddress,SimpleMsg* targetAddress, void *dateAddress){
    int number=this->targetDateAddress(targetAddress,dateAddress);

    targetAddress->dateAddress[number]=0;
    for(int i=number;i < this->locateDateAddress(targetAddress);i++){
        if(number < 19){
            targetAddress->dateAddress[i]=targetAddress->dateAddress[i+1];
        }
    }
    targetAddress->dateAddress[19]=0;
    if(this->locateDateAddress(targetAddress) == 0){
        int positionMsg=this->getMsgPosition(targetAddress->siMsg);
        this->deleSimpleMsgElem(firstAddress,positionMsg);
    }
}

int SimpleMsg::locateDateAddress(SimpleMsg* targetAddress){
    for(int i=0;i <20 ;i++){
        if(targetAddress->dateAddress[i] == 0){
            return i;
        }
    }
}


//================================
int SimpleMsg::getMsgPosition(string siMsg){
    for(int i=0;i < 5;i++){
        if(this->Msg[i] == siMsg){
            return i;
        }
    }
}



//================================
SimpleMsg* SimpleMsg::newSimpleMsgElem(SimpleMsg *firstAddress, int numberMsgList){
    SimpleMsg* targetAddress=new SimpleMsg;
    SimpleMsg* pLastMsg=this->visitListSimpeMsg(firstAddress);
    pLastMsg->nextp=targetAddress;
    targetAddress->siMsg=this->Msg[numberMsgList];
    return targetAddress;
}

SimpleMsg* SimpleMsg::newSimpleMsgElem(SimpleMsg* firstAddress,int numberMsgList, void* addressMsg){
    SimpleMsg* targetAddress=this->newSimpleMsgElem(firstAddress,numberMsgList);
    targetAddress->dateAddress[this->locateDateAddress(targetAddress)]=addressMsg;
    return targetAddress;
}

void SimpleMsg::deleSimpleMsgElem(SimpleMsg *firstAddress, int numberMsgList){
    SimpleMsg* targetAddress=this->locatePriorListSimpeMsg(firstAddress,numberMsgList);
    if(targetAddress->nextp->nextp == NULL){
        delete targetAddress->nextp;
        targetAddress->nextp=NULL;
    }else{
        SimpleMsg* vessel=targetAddress->nextp->nextp;
        delete targetAddress->nextp;
        targetAddress->nextp=vessel;
    }
}
