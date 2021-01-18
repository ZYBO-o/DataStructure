//
// Created by 张永斌 on 2021/1/18.
//

#ifndef DATASTRUCTURE_REALIZATION_DYNAMICARRAY_H
#define DATASTRUCTURE_REALIZATION_DYNAMICARRAY_H

#include "Array.h"

namespace DataStructure
{
    template <typename T>
    class DynamicArray : public Array<T>
    {
    protected:
        int m_length;
    public:
        DynamicArray()
        {
            DynamicArray(0);
        }

        DynamicArray(int length)
        {
            this->m_array = new T[length];

            if(this->m_array != nullptr){

                this->m_length = length;

            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object...");
            }
        }

        DynamicArray(const DynamicArray<T>& obj)
        {
            this->m_array = new T[obj.m_length];

            if(this->m_array != nullptr){

                this->m_length = obj.m_length;

                for (int i = 0; i < obj.m_length; ++i) {
                    this->m_array[i] = obj.m_array[i];
                }

            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object...");
            }

        }

        DynamicArray<T>& operator = (const DynamicArray<T>& obj)
        {
            if(this != &obj)
            {
                T* array = new T(obj.m_length);

                if(array != nullptr)
                {
                    for (int i = 0; i < obj.length(); ++i) {
                        array[i] = obj.m_array[i];
                    }

                    T* temp = this->m_array;

                    this->m_array = array;
                    this->m_length = obj.m_length;

                    delete [] temp;
                } else {
                    THROW_EXCEPTION(NoEnoughMemoryException,"No memory to copy DynamicArray object...");
                }
            }
        }

        int length() const
        {
            return this->m_length;
        }

        void resize(int length)
        {
             if(length != m_length)
             {
                 T* array = new T[length];

                 if(array != nullptr)
                 {
                     int size = (length < m_length ? length : m_length);

                     for (int i = 0; i < size; ++i) {
                         array[i] = this->m_array[i];
                     }

                     T* temp = this->m_array;

                     this->m_array = array;
                     this->m_length = m_length;

                     delete [] temp;



                 } else {
                     THROW_EXCEPTION(NoEnoughMemoryException,"No memory to resize DynamicArray object...");
                 }

             }
        }

        ~DynamicArray()
        {
            delete [] this->m_array;
        }


    };
}

#endif //DATASTRUCTURE_REALIZATION_DYNAMICARRAY_H
