//
// Created by 张永斌 on 2021/4/18.
//

#ifndef DATASTRUCTURE_REALIZATION_TESTQUEUE_H
#define DATASTRUCTURE_REALIZATION_TESTQUEUE_H

#include <iostream>
#include "../HeadCodes/Queue/StaticQueue.h"
#include "../HeadCodes/Queue/LinkQueue.h"

namespace DataStructure {
namespace Test {
namespace QueueTest {

void Queue_Test() {
    std::cout << "[===============================================================]\n";
    std::cout << "[---------------- Run DataStructure Test : Queue ---------------]\n";
    std::cout << "[-------------------------- API test ---------------------------]\n";

    StaticQueue<int, 10> staticQueue;
    LinkQueue<int> linkQueue;


    std::cout << "Add new values in staticQueue." << endl;
    for (int i = 0; i < 10; ++i) {
        staticQueue.add(i);
    }

    std::cout << "Print elements value in staticQueue: " ;
    for (int i = 0; i < 10; ++i) {
        std::cout << staticQueue.front() << " ";
        staticQueue.remove();
    }

    std::cout << std::endl;

    std::cout << "Add new values in linkQueue." << endl;
    for (int i = 0; i < 10; ++i) {
        linkQueue.add(i);
    }

    std::cout << "Print elements value in linkQueue: " ;
    for (int i = 0; i < 10; ++i) {
        std::cout << linkQueue.front() << " ";
        linkQueue.remove();
    }


    std:: cout << std::endl;
    std::cout << "[------------------ Queue Performance Testing ------------------]\n";
}
}
}
}


#endif //DATASTRUCTURE_REALIZATION_TESTQUEUE_H
