//
// Created by 张永斌 on 2021/4/19.
//

#ifndef DATASTRUCTURE_REALIZATION_BTREENODE_H
#define DATASTRUCTURE_REALIZATION_BTREENODE_H

#include "TreeNode.h"

namespace DataStructure {

enum BTNodePos {
    ANY,
    LEFT,
    RIGHT
};

template<typename T>
class BTreeNode : public TreeNode<T>{
public:
    BTreeNode<T>* left;
    BTreeNode<T>* right;

    static BTreeNode<T>* NewNode() {
        BTreeNode<T>* ret = new BTreeNode<T> ();
        if(ret != nullptr) {
            ret->m_flag = true;
        }
        return ret;
    }

    BTreeNode() : left(nullptr), right(nullptr) {}




};
}


#endif //DATASTRUCTURE_REALIZATION_BTREENODE_H
