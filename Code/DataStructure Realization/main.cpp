#include <iostream>
#include "HeadCodes/SmartPointer.h"
#include "HeadCodes/Exception.h"
#include "HeadCodes/DynamicList.h"


using namespace std;
using namespace DataStructure;



int main() {


    DynamicList<int> l(5) ;

    for (int j = 0; j < l.capacity(); ++j) {
        l.insert(0,j);
    }


    for (int i = 0; i < l.length(); ++i) {
        cout << l[i] << endl;
    }

 







}




