#include <iostream>
#include "HeadCodes/SmartPointer.h"
#include "HeadCodes/Exception.h"
#include "HeadCodes/Object.h"

using namespace std;
using namespace DataStructure;


class Test : public Object
{
protected:
    int i;
public:
    Test()
    {
        cout << "test" << endl;
    }
};

int main() {

    Test *obj1 = new Test();
    Test *obj2 = new Test();

    delete obj1;
    delete obj2;




}
