//
// Created by 张永斌 on 2021/4/18.
//

#ifndef DATASTRUCTURE_REALIZATION_QUEUE_H
#define DATASTRUCTURE_REALIZATION_QUEUE_H


#include "../Object/Object.h"

namespace DataStructure{

template<typename T>
class Queue : public Object{
public:
    virtual void add(const T& e) = 0;
    virtual void remove() = 0;
    virtual T front() const = 0;
    virtual void clear() = 0 ;
    virtual int length() const = 0;
};

}

#endif //DATASTRUCTURE_REALIZATION_QUEUE_H
