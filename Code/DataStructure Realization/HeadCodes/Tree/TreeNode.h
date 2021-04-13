//
// Created by 张永斌 on 2021/4/12.
//

#ifndef DATASTRUCTURE_REALIZATION_TREENODE_H
#define DATASTRUCTURE_REALIZATION_TREENODE_H

#include "../Object/Object.h"

namespace DataStructure {

template <typename T>
class TreeNode : public Object{
public:
    T value;
    TreeNode<T>* parent;

    TreeNode() : parent(nullptr){}

    virtual ~TreeNode() = 0;
};

template <typename T>
TreeNode<T>::~TreeNode() {

}
}


#endif //DATASTRUCTURE_REALIZATION_TREENODE_H
