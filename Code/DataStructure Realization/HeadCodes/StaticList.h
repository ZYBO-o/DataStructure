//
// Created by 张永斌 on 2021/1/17.
//

#ifndef DATASTRUCTURE_REALIZATION_STATICLIST_H
#define DATASTRUCTURE_REALIZATION_STATICLIST_H

#include "SeqList.h"

namespace DataStructure
{
    template <typename T, int N>
    class StaticList : public SeqList<T>
    {
    protected:
        T m_space[N]; //顺序存储空间，N为模板参数
    public:
        StaticList() //指定父类成员的具体值
        {
            this->m_array = m_space;
            this->m_length = 0;
        }

        int capacity( ) const
        {
            return N;
        }
    };
}

#endif //DATASTRUCTURE_REALIZATION_STATICLIST_H
