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

public:
    LinkList<GTreeNode<T>*> child;



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
