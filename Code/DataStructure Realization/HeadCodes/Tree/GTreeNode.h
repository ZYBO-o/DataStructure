//
// Created by 张永斌 on 2021/4/13.
//

#ifndef DATASTRUCTURE_REALIZATION_GTREENODE_H
#define DATASTRUCTURE_REALIZATION_GTREENODE_H


#include "TreeNode.h"
#include "../LineStructure/LinkList.h"

namespace DataStructure
{
template<typename T>
class GTreeNode : public TreeNode<T> {
protected:
    bool m_flag;//工厂模式
    //重载new为保护模式
    void* operator new (unsigned long size) throw () {
        return Object::operator new(size);
    }
public:
    LinkList<GTreeNode<T>*> child;
    GTreeNode() : m_flag(false){}

    bool flag () {return m_flag;}

    static GTreeNode<T>* NewNode() {
        GTreeNode<T>* ret = new GTreeNode<T> ();
        if(ret != nullptr) {
            ret->m_flag = true;
        }
        return ret;
    }


};

}

#endif //DATASTRUCTURE_REALIZATION_GTREENODE_H
