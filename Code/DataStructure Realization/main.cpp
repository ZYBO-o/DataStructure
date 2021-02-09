#include <iostream>
#include "HeadCodes/SmartPointer/SmartPointer.h"
#include "HeadCodes/Exception/Exception.h"
#include "HeadCodes/LineStructure/DynamicArray.h"
#include "HeadCodes/LineStructure/StaticArray.h"
#include "HeadCodes/LineStructure/StaticLinkList.h"
#include "HeadCodes/LineStructure/DynamicList.h"
#include "HeadCodes/LineStructure/LinkList.h"
#include "HeadCodes/SmartPointer/SharedPointer.h"



using namespace std;
using namespace DataStructure;


class Test : public Object
{
public:

    int value;

    Test()
    {
        cout<< "test" << endl;
    }
    ~Test()
    {
        cout<< "~test" << endl;
    }
};


int main() {



//    SharedPointer<Test> sp0 = new Test();
//    SharedPointer<Test> sp1 = sp0;
//    SharedPointer<Test> sp2 = nullptr;
//
//    sp2 = sp1;
//
//    sp2->value = 100;
//
//    cout << sp0->value << endl;
//    cout << sp1->value << endl;
//    cout << sp2->value << endl;
//
//    sp2.clear();
//
//    cout << (sp0 == sp1) << endl;
//
//
//    return 0;
}


//    StaticLinkList<int,5> list;
//   // DynamicList<int> list(10);
//
//
//
//
//    for (int i = 0; i < list.capacity() ; ++i) {
//        list.insert(i + 1);
//    }
//
//
//    for (list.move(0,1); !list.end(); list.next()) {
//        cout << list.current() << endl;
//    }


