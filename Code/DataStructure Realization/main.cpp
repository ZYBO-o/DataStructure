#include <iostream>
#include "HeadCodes/SmartPointer.h"
#include "HeadCodes/Exception.h"
#include "HeadCodes/DynamicArray.h"



using namespace std;
using namespace DataStructure;



int main() {

    DynamicArray<int> Dy(5);

    for (int i = 0; i < Dy.length(); ++i) {
        Dy[i] = i * i;
    }

    for (int j = 0; j < Dy.length(); ++j) {
        cout << Dy[j] << endl;
    }




}





