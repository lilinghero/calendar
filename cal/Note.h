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

    SimpleMsg* deleAddress(int year,int month,int day,int number);
    Date* deleAddress(int numberMsgList,int number);

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
