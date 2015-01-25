#include "Ui.h"
#include <iostream>
#include <iomanip>

using namespace std;

   void Ui::pringMessage(int year,int month,int lenghMonth,int firstDay,int targetDay){
       cout<<"   "<<year<<"  yaer    "<<month<<"  month"<<endl;
       cout<<" Mon Tue Wed Thu Fri Sat Sun"<<endl;
        this->totalWeekFormat(lenghMonth,firstDay,targetDay);
    }

    void Ui::totalWeekFormat(int lenghMonth,int firstDay,int targetDay){
        int counterDate=1;

        for(int i=1;i < 43;i++){
                this->singleDateFormat(lenghMonth,firstDay,targetDay,counterDate);
                counterDate++;
               if(i%7 == 0) {
                   cout<<endl;
               }
        }
    }

    void Ui::singleDateFormat(int lenghMonth,int firstDay,int targetDay,int counterDate){
        if(counterDate>=firstDay && counterDate<firstDay+lenghMonth){

            if(lenghMonth != 19 || counterDate < firstDay+2) {
                currentPriDate=counterDate-firstDay+1;
            }else{
                currentPriDate=counterDate-firstDay+1+11;
            }

            if(targetDay == currentPriDate) {
                cout<<setw(4)<<setfill('>')<<currentPriDate;
            }else {
                cout<<setw(4)<<setfill(' ')<<currentPriDate;
            }

        }else{
            cout<<setw(4)<<setfill(' ')<<" ";
        }
    }

