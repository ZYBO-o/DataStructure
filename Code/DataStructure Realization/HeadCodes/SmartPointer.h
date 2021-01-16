//
// Created by 张永斌 on 2021/1/14.
//

#ifndef DATASTRUCTURE_REALIZATION_SMARTPOINTER_H
#define DATASTRUCTURE_REALIZATION_SMARTPOINTER_H

#include "Object.h"

namespace DataStructure
{
    template <typename T>
    class SmartPointer : public Object
    {
    protected:
        T* m_pointer;
    public:
        //构造函数
        SmartPointer(T * p = nullptr)
        {
            m_pointer = p;
        }

        //拷贝函数
        SmartPointer(const SmartPointer<T>& obj)
        {
            m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
        }

        //重载 = 运算符
        SmartPointer<T>& operator = (const SmartPointer<T>& obj)
        {
            //防止运算对象是自己
            if (this != &obj)
            {
                //先释放成员指针指向的堆空间
                delete m_pointer;

                m_pointer = obj.m_pointer;
                const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
            }
            //*this是为了支持连续的赋值
            return *this;
        }

        //重载 * 运算符
        T& operator * ()
        {
            return *m_pointer;
        }

        //重载 -> 运算符
        T* operator -> ()
        {
            return m_pointer;
        }

        //查看是否为空
        bool IsNull()
        {
            return (m_pointer == nullptr);
        }

        T* get()
        {
            return m_pointer;
        }

        ~SmartPointer()
        {
            delete m_pointer;
        }


    };
}




#endif //DATASTRUCTURE_REALIZATION_SMARTPOINTER_H
