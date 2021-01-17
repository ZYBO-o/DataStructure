//
// Created by 张永斌 on 2021/1/17.
//

#ifndef DATASTRUCTURE_REALIZATION_SEQLIST_H
#define DATASTRUCTURE_REALIZATION_SEQLIST_H

#include "List.h"
#include "Exception.h"

namespace DataStructure
{
    template <typename T>
    class SeqList : public List<T>
    {
    protected:
        T* m_array;
        int m_length;
    public:

        bool insert(int i, const T& e)
        {
            bool ret = ((0 <= i) && (i <= m_length));
            ret = ret && (m_length < capacity());

            if(ret)
            {
                for (int index = m_length-1; index >= i; --index) {
                    m_array[index + 1] = m_array[index];
                }
                m_array[i] = e;
                m_length++;
            }
            return ret;
        }

        bool remove(int i)
        {
            bool ret = ((0 <= i) && (i <= m_length));

            if(ret)
            {
                for (int index = i; index < m_length-1; ++index) {
                    m_array[index] = m_array[index + 1];
                }
                m_length--;
            }
            return ret;
        }

        bool set(int i, const T& e)
        {
            bool ret = ((0 <= i) && (i <= m_length));

            if(ret)
            {
                m_array[i] = e;
            }
            return ret;
        }

        bool get(int i, T& e) const
        {
            bool ret = ((0 <= i) && (i <= m_length));

            if(ret)
            {
                e = m_array[i];
            }
            return ret;
        }


        int length() const
        {
            return m_length;
        }

        void clear()
        {
            m_length = 0;
        }

        //顺序存储线性表的数组访问方式
        //非const对象
        T& operator [] (int i)
        {
            bool ret = ((0 <= i) && (i <= m_length));

            try {
                if(ret) {
                    return m_array[i];
                } else {
                    // THROW_EXCEPTION(IndexOutOfBoundsException,"Parameter i is invalid");
                    throw (InvalidOperationException("Parameter i is invalid" ,__FILE_NAME__,__LINE__));
                }
            }
            catch(InvalidOperationException e)
            {
                std::cout << e.message() << std::endl;
                std::cout << e.location() << std::endl;
            }

        }

        //const对象
        T operator [] (int i) const
        {
            //复用代码
            return (const_cast<SeqList<T>&>(*this))[i];
        }

        //顺序存储空间的容量
        //之所以定义为虚函数，是因为空间的分配交给子类来完成
        virtual int capacity() const =0;
    };
}


#endif //DATASTRUCTURE_REALIZATION_SEQLIST_H