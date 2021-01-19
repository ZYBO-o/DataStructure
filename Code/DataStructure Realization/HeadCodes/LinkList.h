//
// Created by 张永斌 on 2021/1/18.
//

#ifndef DATASTRUCTURE_REALIZATION_LINKLIST_H
#define DATASTRUCTURE_REALIZATION_LINKLIST_H

#include "List.h"
#include "Exception.h"

namespace DataStructure
{
    template <typename T>
    class LinkList : public List<T>
    {
    protected:
        struct Node : public Object
        {
            T value;
            Node* next;
        };

        //防止创建头结点的时候调用构造函数
        mutable struct : public Object {
           char reserved[sizeof(T)];
            Node* next;
        } m_header;


        int m_length;

        //添加有关游标
        Node* m_current;
        //游标每次移动的数目
        int m_step;

        //定位函数
        Node* position (int i) const
        {
            Node* current = reinterpret_cast<Node*>(&m_header);

            for (int j = 0; j < i; ++j) {
                current = current->next;
            }

            return current;
        }

        //进行进一步封装
        virtual Node* create()
        {
            return new Node();
        }

        virtual void destroy(Node* pn)
        {
            delete pn;
        }

    public:
        LinkList()
        {
            m_header.next = nullptr;
            m_length = 0;
            m_step = 1;
            m_current = nullptr;
        }


        bool insert(int i, const T& e)
        {
            bool ret = ((0 <= i) && (i <= m_length));
            if(ret)
            {
                Node* node = create();

                if(node != nullptr){

                    Node* current = position(i);

                    node->value = e;
                    node->next = current->next;
                    current->next = node;

                    m_length++;

                } else {
                    THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory to insert new elements in LinkList");
                }

            }

            return ret;
        }

        bool insert(const T& e)
        {
            return insert(m_length,e);
        }

        bool remove(int i)
        {
            bool ret = ((0 <= i) && (i < m_length));
            if(ret)
            {
                Node* current = position(i);

                Node* toDel = current->next;
                current->next = toDel->next;

                destroy(toDel);

                m_length--;
            }
            return ret;
        }


        bool set(int i, const T& e)
        {
            bool ret = ((0 <= i) && (i < m_length));
            if(ret)
            {
                Node* current = position(i);

               current->next->value = e;
            }
            return ret;
        }

        bool get(int i, T& e) const
        {
            bool ret = ((0 <= i) && (i < m_length));
            if(ret)
            {
                Node* current = position(i);

               e =  current->next->value;
            }
            return ret;
        }

        T get(int i) const
        {
            T ret;

            if(get(i,ret))
            {
                return ret;
            } else {
                THROW_EXCEPTION(IndexOutOfBoundsException,"Invalid parameter i to get LinkList element ...");
            }
            return ret;
        }

        int find(const T& e) const
        {
            int ret = -1;
            int index = 0;
            Node* node = m_header.next;

            while (node)
            {
                if(node->value == e)
                {
                    ret = index;
                    break;
                } else {
                    node = node->next;
                    index++;
                }
            }
            return ret;
        }


        //将游标定位到目标位置
        bool move(int i, int step = 1)
        {
            bool ret = (0 <= i) && (i < m_length) && (step > 0);

            if(ret)
            {
                m_current = position(i)->next;
                m_step = step;
            }
            return ret;
        }

        //游标是否到达尾部 (是否为空)
        bool end()
        {
            return (m_current == nullptr);
        }

        //获取游标指向的数据元素
        T current()
        {
            if(!end())
            {
                return m_current->value;
            } else {
                THROW_EXCEPTION(InvalidOperationException,"No value at current position ...");
            }
        }

        //移动游标
        bool next()
        {
            int i = 0;
            while( (i < m_step) && !end())
            {
                m_current = m_current->next;
                i++;
            }

            return (i == m_step);

        }


        int length() const
        {
            return  m_length;
        }

        void clear()
        {
            while (m_header.next)
            {
                Node* toDel = m_header.next;

                m_header.next = toDel->next;

                destroy(toDel);
            }
            m_length = 0;
        }

        ~LinkList()
        {
            clear();
        }
    };
}


#endif //DATASTRUCTURE_REALIZATION_LINKLIST_H
