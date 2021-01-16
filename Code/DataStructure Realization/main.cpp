#include <iostream>
#include "HeadCodes/SmartPointer.h"

using namespace std;
using namespace DataStructure;


class Test
{
protected:
    int test;
public:
    Test()
    {
        cout<< "Test created" << endl;
    }
};

double divide(double a, double b)
{
    //因为浮点数的表述是不精确的，所以最好不要通过等号的方式进行比较
    const double delta = 0.000000000000001;
    double ret = 0;
    if (!((-delta < b) && (delta > b))) {
        ret = a / b;
    } else {
        throw 0; //产生除0异常
    }

    return ret;
}

int main() {
    try{
        divide( 1.0 , 0);
    }catch (int) {
        cout << "divided 0" <<endl;
    }
    return 0;
}
