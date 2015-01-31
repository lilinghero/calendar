#include "Calculate.h"
#include <iostream>
#include <string>
using namespace std;

const int Calculate::standarWeek[]={6,2,2,5,7,3,5,1,4,6,2,4};

int Calculate::recursiveFirstDate(int year, int month){

        if(month <= 2){
            firstDate=this->mobileUnitPerYear(year-1);
        }else if ((month > 2 && year != 1752)||(year == 1752 && month >= 10)){
            firstDate=this->mobileUnitPerYear(year);
        }else if(year == 1752 && month < 10){
            firstDate=2;
        }

        if(year == 1){
            firstDate=standarWeek[month-1];
        }else{
            firstDate=(firstDate+this->recursiveFirstDate(year-1,month))%7;
        }
        return firstDate;
}

int Calculate::lenghMonth(int year, int month){
        int lenMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};

        if(this->mobileUnitPerYear(year) == 2||this->mobileUnitPerYear(year) == 5) {
            lenMonth[1]=29;
        }
        if(month == 9 && year == 1752) {
            lenMonth[8]=19;
        }

        return lenMonth[month-1];
}
int Calculate::mobileUnitPerYear(int year){
        if(year == 1752) {
            return 5;
        }else if(year < 1752 && year%4 == 0) {
            return 2;
        }else if(year > 1752 && ((year%4 == 0 && year%100 != 0) || year%400 == 0)) {
            return 2;
        }else{
            return 1;
        }
}

