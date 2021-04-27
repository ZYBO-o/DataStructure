//
// Created by 张永斌 on 2021/4/13.
//

#ifndef DATASTRUCTURE_REALIZATION_GTREE_H
#define DATASTRUCTURE_REALIZATION_GTREE_H

#include "Tree.h"
#include "GTreeNode.h"
#include "../Queue/LinkQueue.h"

namespace DataStructure
{

template<typename T>
class GTree : public Tree<T> {
protected:


    //为层次遍历定义队列
    LinkQueue<GTreeNode<T>*> m_queue;
    //功能函数：根据值查找函数
    GTreeNode<T>* find(GTreeNode<T>* node, const T& value) const {
        GTreeNode<T>* ret = nullptr;

        if(node != nullptr) {
            if(node->value == value) {
                return node;
            } else {
                //如果不是node结点，则遍历其子结点，进行递归操作
                for (node->child.move(0); !node->child.end() && (ret == nullptr); node->child.next()) {
                    ret = find(node->child.current(), value);
                }
            }
        }
        return ret;
    }
    //功能函数：根据结点查找函数
    GTreeNode<T>* find(GTreeNode<T>* node, const GTreeNode<T>* obj) const {
        GTreeNode<T>* ret = nullptr;

        if(obj != nullptr) {
            if(node == obj) {
                return node;
            } else {
                for (node->child.move(0); !node->child.end() && (ret == nullptr); node->child.next()) {
                    ret = find(node->child.current(), obj);
                }
            }
        }

        return ret;
    }
    //功能函数：清除操作
    void free(GTreeNode<T>* node) {
        if(node != nullptr) {
            for (node->child.move(0); !node->child.end() ; node->child.next()) {
                free(node->child.current());
            }
            //free只能删除堆中的数据，如果是在栈或全局数据区，则会出问题
            //free(node);
            if(node->flag()) {
                delete node;
            }
        }
    }
    //功能函数： 删除结点
    void remove(GTreeNode<T>* node, GTree<T>*& ret) {
        ret = new GTree<T>();

        if(ret == nullptr) {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new tree..");
        } else {
            if( node == root()) {
                this->m_root = nullptr;
            } else {
                //定义链表引用，找到需要移除的节点所在的链表
                LinkList<GTreeNode<T>*>& child = dynamic_cast<GTreeNode<T>*>(node->parent)->child;
                //移除链表所在结点
                child.remove(child.find(node));
                node->parent = nullptr;
            }
            //当做树进行返回
            ret->m_root = node;
        }
    }
    //功能函数： 统计树中的结点数
    int nodecount(GTreeNode<T>* node) const{
        int ret = 0;

        if(node != nullptr) {
            //不为空，至少有一个
            ret = 1;
            //遍历 + 递归
            for (node->child.move(0) ; !node->child.end() ; node->child.next()) {
                ret += nodecount(node->child.current());
            }
        }
        return ret;
    }
    //功能函数：计算树的高度
    int treeheight(GTreeNode<T>* node) const {
        int ret = 0;

        if(node != nullptr) {
            for(node->child.move(0); !node->child.end(); node->child.next()) {
                int h = treeheight(node->child.current());
                if(ret < h) {
                    ret = h;
                }
            }

            ret = ret + 1;
        }

        return ret;
    }
    //功能函数：计算树的度数
    int treedegree(GTreeNode<T>* node) const {
        int ret = 0;

        if(node != nullptr) {
            ret = node->child.length();


            for (node->child.move(0) ;  !node->child.end(); node->child.next()) {
                int d = treedegree(node->child.current());

                if(ret < d){
                    ret = d;
                }
            }
        }

        return ret;
    }
public:
    GTree() {}

    bool insert(TreeNode<T>* node) {
        bool ret = true;

        if(node != nullptr) {

            //根结点为空，则直接插入
            if(this->m_root == nullptr) {
                node->parent = nullptr;
                this->m_root = node;
            } else {
                //查找需要插入位置的前驱结点
                GTreeNode<T>* np = find(node->parent);
                //确定找到其父节点
                if(np != nullptr) {
                    auto n = dynamic_cast<GTreeNode<T>*>(node);
                    //确定没有重复插入
                    if(np->child.find(n) < 0) {
                        //插入链表中
                        np->child.insert(n);
                    } else {
                        return false;
                    }
                } else {
                    THROW_EXCEPTION(InvalidOperationException, "Invalid parent tree node");
                }
            }

        } else {
            THROW_EXCEPTION(InvalidOperationException, "Parameter tree node cannot be nullptr");
        }

        return ret;
    }

    bool insert(const T& value, TreeNode<T>* parent) {
        bool ret = true;

        GTreeNode<T>* node = GTreeNode<T>::NewNode();

        if(node != nullptr) {
            node->value = value;
            node->parent = parent;

            insert(node);
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create a new tree node to insert");
        }

        return ret;
    }

    SharedPointer<Tree<T>> remove(const T& value) {
        GTree<T>* ret = nullptr;
        //找到需要删除的结点所在
        GTreeNode<T>* node = find(value);

        if(node == nullptr) {
            THROW_EXCEPTION(InvalidParameterException, "cannot find the node via parameter value...");
        } else {
            //删除，并返回树
            remove(node, ret);
            m_queue.clear();
        }
        return ret;
    }

    SharedPointer<Tree<T>> remove(TreeNode<T>* node)  {
        GTree<T>* ret = nullptr;
        //找到需要删除的结点所在
        node = find(node);

        if(node == nullptr) {
            THROW_EXCEPTION(InvalidParameterException, "parameter node is invalid...");
        } else {
            //删除，并返回树
            remove(dynamic_cast<GTreeNode<T>*>(node), ret);
            m_queue.clear();
        }
        return ret;
    }

    GTreeNode<T>* find(const T& value) const {
        //直接调用功能函数
        return find(root(), value);
    }

    GTreeNode<T>* find(TreeNode<T>* node) const {
        return find(root(), dynamic_cast<GTreeNode<T>*>(node));
    }

    GTreeNode<T>* root() const {
        return dynamic_cast<GTreeNode<T>*>(this->m_root);
    }

    int degree() const {
        return treedegree(root()) + 1;
    }

    int count() const {
        return nodecount(root());
    }

    int height() const {
        return treeheight(root());
    }

    void clear() {
        free(root());
        this->m_root = nullptr;
        m_queue.clear();
    }

    //层次遍历初始化
    bool begin () {
        bool ret = (root() != nullptr);

        if (ret) {
            m_queue.clear();
            m_queue.add(root());
        }

        return ret;
    }

    //判断层次遍历是否已经完成
     bool end () {
        return (m_queue.length() == 0);
    }

    //层序遍历游标指向下一个结点
    bool next(){
        bool ret = (m_queue.length() > 0);

        if(ret) {
            GTreeNode<T>* node = m_queue.front();
            m_queue.remove();
            for (node->child.move(0); !node->child.end(); node->child.next()) {
                //孩子结点压入队列
                m_queue.add(node->child.current());
            }
        }

        return ret;
    }

    //返回游标指向的结点数据元素
    T current() {
        if( !end() ) {
            return m_queue.front()->value;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No value at current position.. ");
        }
    }

    ~GTree() {
        clear();
    }
};
}


#endif //DATASTRUCTURE_REALIZATION_GTREE_H
