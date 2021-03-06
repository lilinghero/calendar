#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;
class Date
{
public:

    Date();
    //================================
    int emptyListDate(Date* firstAddress);
    Date* visitListDate(Date* firstAddress);
    int lengthList(Date* firstAddress);
    //================================
    Date* locateListDate(Date* firstAddress,int year,int month,int day);
    Date* locatePriorListDate(Date* firstAddress,int year, int month, int day);
    //================================
    void* getSimpleMsgAddress(Date* firstAddress,int year,int month,int day);
    //================================
    int targetSimpleMsgAddress(Date* targetAddress,void * msgAddress);
    void deleSimpleMsgAddress(Date* firstAddress,Date* targetAddress,void * msgAddress);
    int locateSimpleMsgAddress(Date* targetAddress);
    //================================
    Date* newDateElem(Date* firstAddress,int year,int month,int day);
    Date* newDateElem(Date* firstAddress,int year,int month,int day,void* addressMsg);
    void deleDateElem(Date* firstAddress,int year,int month,int day);
    //void deleDateElem(int year,int month,int day,int numberMsgList);


    int year;
    int month;
    int day;
    void* SimpleMsgAddress[5];
    string otherMsg;
    Date* nextp;
};
#endif // DATE_H
