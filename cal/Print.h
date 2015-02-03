#ifndef PRINT_H
#define PRINT_H
#include "Note.h"
class Print
{
public:
    void showMsg(Note* pNote,Date* firstAddress,int year,int month,int day);
    void showDate(Note* pNote,SimpleMsg* firstAddress,int numberMsgList);
};


#endif // PRINT_H
