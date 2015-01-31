#ifndef NOTE_H
#define NOTE_H
#include <string>
using namespace std;
class Note
{
 public:
    Note();

    class Date
    {
    public:
        int year;
        int month;
        int day;
        void* SimpleMsgAddress[5];
        string otherMsg;
        Note::Date* nextp;
    };

    class SimpleMsg
    {
    public:
        string siMsg;
        void* dateAddress[20];
        Note::SimpleMsg* nextp;
    };

    int emptyListDate();
    int emptyListSimpeMsg();
    Note::Date* visitListDate(Note::Date* firstAddress);
    Note::SimpleMsg* visitListSimpeMsg(Note::SimpleMsg* firstAddress);
    int lengthList(Note::Date* firstAddress);
    int lengthList(Note::SimpleMsg* firstAddress);
    Note::Date* locateListDate(Note::Date* firstAddress,int year,int month,int day);
    Note::SimpleMsg* locateListSimpeMsg(Note::SimpleMsg* firstAddress,int numberMsgList);

    void putElem(int year,int month,int day,int numberMsgList);
    void deleElem(int year,int month,int day);
    void clearALL();

    Date headDate;
    Date* pHeadDate;
    SimpleMsg headSimpMsg;
    SimpleMsg* pHeadSimpMsg;


    static const string  Msg[5];
};

#endif // NOTE_H
