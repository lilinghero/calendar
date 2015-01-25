#include <iostream>
//#include <string>
#include <iomanip>
#include "Calculate.h"
#include "Ui.h"
using namespace std;

const int Calculate::standarWeek[]={6,2,2,5,7,3,5,1,4,6,2,4};

int main()
{
    Ui putMsg;
    Calculate calMethod;
    int year,month,day;
    cin>>year>>month>>day;
    putMsg.pringMessage(year,month,calMethod.lenghMonth(year,month),calMethod.recursiveFirstDate(year,month),day);
}























