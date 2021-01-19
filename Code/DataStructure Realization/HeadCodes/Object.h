//
// Created by 张永斌 on 2021/1/14.
//

#ifndef DATASTRUCTURE_REALIZATION_OBJECT_H
#define DATASTRUCTURE_REALIZATION_OBJECT_H


namespace DataStructure
{
    class Object
    {
    public:
        void* operator new (unsigned long size) throw();
        void operator delete (void* p);
        void* operator new[] (unsigned long size) throw();
        void operator delete[] (void* p);
        bool operator == (const Object& object);
        bool operator != (const Object& object);
        virtual ~Object() = 0;
    };
}

#endif //DATASTRUCTURE_REALIZATION_OBJECT_H
