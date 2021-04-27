//
// Created by 张永斌 on 2021/4/12.
//

#ifndef DATASTRUCTURE_REALIZATION_TREENODE_H
#define DATASTRUCTURE_REALIZATION_TREENODE_H

#include "../Object/Object.h"

namespace DataStructure {

template <typename T>
class TreeNode : public Object{
protected:
    bool m_flag;//工厂模式


    TreeNode(const TreeNode<T>&) ;
    TreeNode<T>& operator = (const TreeNode<T>&);

    //重载new为保护模式
    void* operator new (unsigned long size) throw () {
        return Object::operator new(size);
    }

public:
    T value;
    TreeNode<T>* parent;

    TreeNode() : parent(nullptr),  m_flag(false){}

    bool flag () {return m_flag;}

    virtual ~TreeNode() = 0;
};

template <typename T>
TreeNode<T>::~TreeNode() {

}
}


#endif //DATASTRUCTURE_REALIZATION_TREENODE_H
