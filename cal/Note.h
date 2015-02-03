#ifndef NOTE_H
#define NOTE_H
#include <string>
#include "Date.h"
#include "SimpleMsg.h"
using namespace std;
class Note
{
 public:
    Note();

    void putElem(int year,int month,int day,int numberMsgList);

    SimpleMsg* getMsgPointer(Date* firstAddress,int year,int month,int day,int numberAddress);
    Date* getDatePointer(SimpleMsg* firstAddress,int numberMsgList,int numberAddress);

    void deleElem(int year,int month,int day);
    void deleElem(int numberMsgList);
    void deleElem(int year, int month, int day,int numberMsgList);

    void clearSingleList(Date* pHeadDate);
    void clearSingleList(SimpleMsg* pHeadSimpMsg);
    void clearAll();

    Date headDate;
    Date* pHeadDate;
    SimpleMsg headSimpMsg;
    SimpleMsg* pHeadSimpMsg;
};

#endif // NOTE_H
