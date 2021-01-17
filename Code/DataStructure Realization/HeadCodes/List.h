//
// Created by 张永斌 on 2021/1/16.
//

#ifndef DATASTRUCTURE_REALIZATION_LIST_H
#define DATASTRUCTURE_REALIZATION_LIST_H

#include "Object.h"

namespace DataStructure
{
    template <typename T>
    class List : public Object
    {
    protected:
        //进制拷贝与赋值操作
        List(const List&);
        List& operator = (const List&);
    public:
        List() {}
        //尾部插入
        virtual bool insert(const T& e) = 0;
        virtual bool insert(int i, const T& e) = 0;
        virtual bool remove(int i) = 0;
        virtual bool set(int i, const T& e) = 0;
        virtual bool get(int i, T& e) const = 0;
        virtual int length() const =0;
        virtual void clear() = 0;
    };
}



#endif //DATASTRUCTURE_REALIZATION_LIST_H
