//
// Created by 张永斌 on 2021/1/20.
//

#ifndef DATASTRUCTURE_REALIZATION_POINTER_H
#define DATASTRUCTURE_REALIZATION_POINTER_H

#include "../Object/Object.h"

namespace DataStructure
{
    template <typename T>
    class Pointer : public Object
    {
    protected:
        T* m_pointer;
    public:
        Pointer(T* p = nullptr)
        {
            m_pointer = p;
        }

        T* operator -> ()
        {
            return m_pointer;
        }

        T& operator * ()
        {

            return *m_pointer;
        }

        const T* operator -> () const
        {
            return m_pointer;
        }

        const T& operator * () const
        {

            return *m_pointer;
        }

        bool IsNull() const
        {
            return (m_pointer == nullptr);
        }

        T* get() const
        {
            return m_pointer;
        }

        //不实现具体的析构函数，则Pointer就是抽象类

    };
}

#endif //DATASTRUCTURE_REALIZATION_POINTER_H
