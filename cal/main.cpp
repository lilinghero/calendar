#include <iostream>
//#include <string>
#include <iomanip>
#include "Calculate.h"
#include "Ui.h"
using namespace std;



int main()
{
    Ui putMsg;
    Calculate calMethod;
    int year,month,day;
    cin>>year>>month>>day;
    putMsg.pringMessage(year,month,calMethod.lenghMonth(year,month),calMethod.recursiveFirstDate(year,month),day);
}























