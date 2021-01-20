//
// Created by 张永斌 on 2021/1/14.
//

#ifndef DATASTRUCTURE_REALIZATION_SMARTPOINTER_H
#define DATASTRUCTURE_REALIZATION_SMARTPOINTER_H

#include "Pointer.h"

namespace DataStructure
{
    template <typename T>
    class SmartPointer : public Pointer<T>
    {
    public:
        //构造函数
        SmartPointer(T * p = nullptr) : Pointer<T>(p)
        {

        }

        //拷贝函数
        SmartPointer(const SmartPointer<T>& obj)
        {
            this->m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
        }

        //重载 = 运算符
        SmartPointer<T>& operator = (const SmartPointer<T>& obj)
        {
            //防止运算对象是自己
            if (this != &obj)
            {
                //先释放成员指针指向的堆空间
                T* p = this->m_pointer;

                this->m_pointer = obj.m_pointer;

                const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;

                delete p;
            }
            //*this是为了支持连续的赋值
            return *this;
        }


        ~SmartPointer()
        {
            delete this->m_pointer;
        }


    };
}




#endif //DATASTRUCTURE_REALIZATION_SMARTPOINTER_H
