#include <iostream>
#include "HeadCodes/SmartPointer.h"
#include "HeadCodes/Exception.h"
#include "HeadCodes/DynamicArray.h"
#include "HeadCodes/StaticArray.h"
#include "HeadCodes/StaticLinkList.h"
#include "HeadCodes/DynamicList.h"
#include "HeadCodes/LinkList.h"



using namespace std;
using namespace DataStructure;





int main() {

    //StaticLinkList<int,5> list;
    DynamicList<int> list(10);


    for (int i = 0; i < 5; ++i) {
        list.insert(i);
    }

//    for (list.move(0,1); !list.end(); list.next()) {
//        cout << list.current() << endl;
//    }






}






