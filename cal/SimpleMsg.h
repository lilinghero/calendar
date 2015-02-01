#ifndef SIMPLEMSG_H
#define SIMPLEMSG_H
#include <string>
using namespace std;
class SimpleMsg
{
public:

    SimpleMsg();

    int emptyListSimpeMsg(SimpleMsg* firstAddress);
    SimpleMsg* visitListSimpeMsg(SimpleMsg* firstAddress);
    int lengthList(SimpleMsg* firstAddress);

    SimpleMsg* locateListSimpeMsg(SimpleMsg* firstAddress,int numberMsgList);
    SimpleMsg* locatePriorListSimpeMsg(SimpleMsg* firstAddress,int numberMsgList);

    void* getDateAddress(SimpleMsg* firstAddress,int numberMsgList);
    int targetDateAddress(void* targetAddress);
    void deleDateAddress(int number);
    int locateDateAddress();

    SimpleMsg* newSimpleMsgElem(SimpleMsg* firstAddress,SimpleMsg* headAddress,int numberMsgList);
    SimpleMsg* newSimpleMsgElem(SimpleMsg* firstAddress,SimpleMsg* headAddress,int numberMsgList,void* addressMsg);
    void deleSimpleMsgElem(SimpleMsg* firstAddress,int numberMsgList);
    //void deleSimpleMsgElem(int year,int month,int day,int numberMsgList);

    string siMsg;
    void* dateAddress[20];
    SimpleMsg* nextp;

    static const string  Msg[5];
};
#endif // SIMPLEMSG_H
