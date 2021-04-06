#include <iostream>
#include "HeadCodes/SmartPointer/SmartPointer.h"
#include "HeadCodes/Exception/Exception.h"
#include "HeadCodes/LineStructure/DynamicArray.h"
#include "HeadCodes/LineStructure/StaticArray.h"
#include "HeadCodes/LineStructure/StaticLinkList.h"
#include "HeadCodes/LineStructure/DynamicList.h"
#include "HeadCodes/LineStructure/LinkList.h"
#include "HeadCodes/SmartPointer/SharedPointer.h"
#include "HeadCodes/Sort/Sort.h"

using namespace std;
using namespace DataStructure;


int main() {



    int Array[10] {-1,3,2,5,7,12,55,8,-5,0};
    //Sort::Select(Array, 10, Max);
    //Sort::Insert(Array,10,Max);
    //Sort::Bubble(Array,10,Max);
    //Sort::Shell(Array, 10, Max);
    //Sort::Merge(Array,10,Max);
    Sort::Quick(Array,10, Min);
    for (int i : Array) {
        cout << i << " ";
    }



    return 0;
}




