//
// Created by 张永斌 on 2021/4/18.
//

#ifndef DATASTRUCTURE_REALIZATION_LINKQUEUE_H
#define DATASTRUCTURE_REALIZATION_LINKQUEUE_H


#include "Queue.h"
#include "../Exception/Exception.h"
#include "../LineStructure/LinkList.h"

namespace DataStructure {

    template<typename T>
    class LinkQueue : public Queue<T> {
    protected:
       LinkList<T> m_list;

    public:
        LinkQueue()  {}



        void add(const T& e) {
                m_list.insert(e);
        }

        void remove() {
            if (m_list.length() > 0) {
                m_list.remove(0);
            } else {
                THROW_EXCEPTION(InvalidOperationException, "No element in current queue to remove value..");
            }
        }

        T front() const {
            if(m_list.length() > 0) {
                return m_list.get(0);
            } else {
                THROW_EXCEPTION(InvalidOperationException, "No element in current queue to get front value..");
            }
        }

        void clear() {
           m_list.clear();
        }

        int length() const {
            return m_list.length();
        }


    };

}


#endif //DATASTRUCTURE_REALIZATION_LINKQUEUE_H
