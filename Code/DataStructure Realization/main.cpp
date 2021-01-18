#include <iostream>
#include "HeadCodes/SmartPointer.h"
#include "HeadCodes/Exception.h"
#include "HeadCodes/DynamicArray.h"
#include "HeadCodes/DynamicList.h"



using namespace std;
using namespace DataStructure;



int main() {

    DynamicArray<int> s1(5);

    for (int i = 0; i < s1.length(); ++i) {
        s1[i] = (i * i);
    }



    DynamicArray<int> s2(10) ;



    cout << s2.length() << endl;




}




