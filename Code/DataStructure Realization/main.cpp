#include <iostream>
#include "HeadCodes/SmartPointer.h"
#include "HeadCodes/Exception.h"

using namespace std;
using namespace DataStructure;


int main() {


    try{
        THROW_EXCEPTION(ArithmeticException, "Test");
    }catch (const ArithmeticException e) {
        cout << "const ArithmeticException e" <<endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    return 0;
}
