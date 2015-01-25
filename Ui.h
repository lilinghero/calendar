#ifndef UI_H
#define UI_H
class Ui
{
public:
   void pringMessage(int year,int month,int lenghMonth,int firstDay,int targetDay);

    void totalWeekFormat(int lenghMonth,int firstDay,int targetDay);

    void singleDateFormat(int lenghMonth,int firstDay,int targetDay,int counterDate);

    int currentPriDate;
};
#endif // UI_H
