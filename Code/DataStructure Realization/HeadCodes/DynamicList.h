//
// Created by 张永斌 on 2021/1/17.
//

#ifndef DATASTRUCTURE_REALIZATION_DYNAMICLIST_H
#define DATASTRUCTURE_REALIZATION_DYNAMICLIST_H

#include <iostream>
#include "SeqList.h"
#include "Exception.h"


namespace DataStructure
{
    template <typename T>
    class DynamicList : public SeqList<T>
    {
    protected:
        int m_capacity; //动态存储空间的大小
    public:
        DynamicList(int capacity) //申请空间
        {
            this->m_array = new T[capacity];

            if (this->m_array != nullptr) {

                this->m_length = 0;
                this->m_capacity = capacity;

            } else {

                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicList object ...");

            }

        }

        int capacity() const {
            return m_capacity;
        }

        void resize(int capacity) //重新设置顺序存储空间的大小
        {
            if (capacity != this->m_capacity)
            {
                T* array = new T[capacity];

                if(array != nullptr){

                    int length = (this->m_length < capacity ? this->m_length : capacity);

                    for (int i = 0; i < length; ++i) {
                        array[i] = this->m_array[i];
                    }

                    //临时变量指向堆空间
                    T* temp = this->m_array;

                    this->m_array = array;
                    this->m_length = length;
                    this->m_capacity = capacity;

                    //删除的是堆空间，还得再思考动态内存的内容
                    delete temp;


                } else {

                    THROW_EXCEPTION(NoEnoughMemoryException,"No memory to resize DynamicList object ...");
                }
            }
        }

        ~DynamicList() //归还空间
        {
            delete[] this->m_array;
        }
    };
}



#endif //DATASTRUCTURE_REALIZATION_DYNAMICLIST_H
