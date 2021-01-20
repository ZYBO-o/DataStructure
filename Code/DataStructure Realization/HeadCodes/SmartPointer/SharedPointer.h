//
// Created by 张永斌 on 2021/1/20.
//

#ifndef DATASTRUCTURE_REALIZATION_SHAREDPOINTER_H
#define DATASTRUCTURE_REALIZATION_SHAREDPOINTER_H

#include <cstdlib>
#include "Pointer.h"
#include "../Exception/Exception.h"

namespace DataStructure {
    template<typename T>
    class SharedPointer : public Pointer<T> {
    protected:
        int *m_ref;

        //封装内部使用的函数
        void assign(const SharedPointer<T> &obj) {
            this->m_ref = obj.m_ref;
            this->m_pointer = obj.m_pointer;

            if (this->m_ref) {
                (*this->m_ref)++;
            }
        }

    public:
        SharedPointer(T *p = nullptr) : m_ref(nullptr) {
            if (p) {
                this->m_ref = static_cast<int *>(std::malloc(sizeof(int)));
                if (this->m_ref) {
                    *(this->m_ref) = 1;
                    this->m_pointer = p;
                } else {
                    THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create SharedPointer object ...");
                }
            }
        }

        SharedPointer(const SharedPointer<T> &obj) : Pointer<T>(nullptr)
        {
            assign(obj);
        }

        SharedPointer<T> &operator=(const SharedPointer<T> &obj) {
            if (this != &obj) {
                //先把当前的智能指针置空
                clear();

                assign(obj);
            }

            return *this;
        }


        void clear() {
            T *toDel = this->m_pointer;
            int *ref = this->m_ref;

            this->m_ref = nullptr;
            this->m_pointer = nullptr;

            if (ref) {
                (*ref)--;

                if (*ref == 0) {
                    free(ref);
                    delete toDel;
                }
            }
        }

        ~SharedPointer() {
            clear();
        }



    };


    template <typename T>
    bool operator == (const SharedPointer<T>&obj1, const SharedPointer<T>& obj2)
    {
        return (obj1.get() == obj2.get());
    }

    template <typename T>
    bool operator != (const SharedPointer<T>&obj1, const SharedPointer<T>& obj2)
    {
        return (obj1.get() != obj2.get());
    }


}

#endif //DATASTRUCTURE_REALIZATION_SHAREDPOINTER_H
