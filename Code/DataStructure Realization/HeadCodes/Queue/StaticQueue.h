//
// Created by 张永斌 on 2021/4/18.
//

#ifndef DATASTRUCTURE_REALIZATION_STATICQUEUE_H
#define DATASTRUCTURE_REALIZATION_STATICQUEUE_H

#include "Queue.h"
#include "../Exception/Exception.h"

namespace DataStructure {

template<typename T, int N>
class StaticQueue : public Queue<T> {
protected:
    T m_space[N];
    int m_front;
    int m_rear;
    int m_length;

public:
    StaticQueue() : m_front(0), m_rear(0), m_length(0) {}

    int capacity() const { return N; }

    void add(const T& e) {
        if(m_length < N) {
            m_space[m_rear] = e;
            //循环计数法
            m_rear = (m_rear + 1) % N;
            ++m_length;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No space in current queue to add new value..");
        }
    }

    void remove() {
        if (m_length > 0) {
            //循环计数法
            m_front = (m_front + 1) % N;
            --m_length;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue to remove value..");
        }
    }

    T front() const {
        if(m_length > 0) {
            return m_space[m_front];
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue to get front value..");
        }
    }

    void clear() {
        m_front = 0;
        m_length = 0;
        m_rear = 0;
    }

    int length() const {
        return m_length;
    }


};

}


#endif //DATASTRUCTURE_REALIZATION_STATICQUEUE_H
