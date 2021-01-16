//
// Created by 张永斌 on 2021/1/16.
//

#include "../HeadCodes/Object.h"
#include <iostream>
#include <cstdlib>

using namespace std;

namespace DataStructure
{
    void* Object::operator new(unsigned long size) throw()
    {
        return malloc(size);
    }

    void Object::operator delete(void * p)
    {
        free(p);
    }

    void* Object::operator new[](unsigned long size) throw()
    {
        return malloc(size);
    }

    void Object::operator delete[](void * p)
    {
        free(p);
    }

    Object::~Object() {}
}



