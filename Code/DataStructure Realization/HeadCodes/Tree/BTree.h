//
// Created by 张永斌 on 2021/4/19.
//

#ifndef DATASTRUCTURE_REALIZATION_BTREE_H
#define DATASTRUCTURE_REALIZATION_BTREE_H

#include "Tree.h"
#include "BTreeNode.h"
#include "../Exception/Exception.h"
#include "../Queue/LinkQueue.h"
#include "../LineStructure/DynamicArray.h"

namespace DataStructure {

//枚举遍历方式
enum  BTTraversal{
    PreOrder,
    InOrder,
    PostOrder
};

template<typename T>
class BTree : public Tree<T> {
protected:
    //层次遍历所需的队列
    LinkQueue<BTreeNode<T>*> m_queue;
    //功能函数，根据值来进行查找
    BTreeNode<T>* find(BTreeNode<T>* node, const T& value) const {
        BTreeNode<T>* ret = nullptr;

        if(node != nullptr) {
            if(value == node->value) {
                ret = node;
            } else {
                if(ret == nullptr) {
                    ret = find(node->left, value);
                }
                if (ret == nullptr) {
                    ret = find(node->right, value);
                }
            }
        }
        return ret;
    }
    //功能函数，根据结点进行查找
    BTreeNode<T>* find(BTreeNode<T>* node, BTreeNode<T>*obj) const {
        BTreeNode<T>* ret = nullptr;

        if(node == obj) {
            return node;
        } else {
            if(node != nullptr) {
                if(ret == nullptr) {
                    ret = find(node->left, obj);
                }
                if(ret == nullptr) {
                    ret = find(node->right, obj);
                }
            }
        }
        return ret;
    }
    //功能函数，插入新结点
    bool insert(BTreeNode<T>* node, BTreeNode<T>* np, BTNodePos pos) {
        bool ret = true;
        if(pos == LEFT) {
            if(np->left == nullptr) {
                np->left = node;
            } else {
                ret = false;
            }

        } else if(pos == RIGHT) {
            if(np->right == nullptr) {
                np->right = node;
            } else {
                ret = false;
            }

        } else if(pos == ANY) {
            if(np->left == nullptr) {
                np->left = node;
            } else if(np->right == nullptr) {
                np->right = node;
            } else {
                ret = false;
            }

        } else {
            ret = false;
        }

        return ret;
    }

    //功能函数：删除节点操作
    void Remove(BTreeNode<T>* node, BTree<T>*& ret) {
        ret = new BTree<T>();

        if(ret == nullptr) {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to creat new tree");
        } else {
            if( root() == node ) {
                this->m_root = nullptr;
            } else {
                BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);

                //父子结点断开
                if(parent->left == node) {
                    parent->left = nullptr;
                } else if(parent->right == node) {
                    parent->right = nullptr;
                }

                node->parent = nullptr;
            }
            //新建树的根结点指向node子树
            ret->m_root = node;
        }
    }
    //功能函数：清除二叉树的操作
    void free(BTreeNode<T>* node) {
        if(node != nullptr) {
            free(node->left);
            free(node->right);

            if(node->flag()) {
                delete node;
            }
        }
    }
    //功能函数：计算二叉树结点
    int count(BTreeNode<T>* node) const {
        int ret = 0;
        if( node != nullptr) {
            ret = count(node->left) + count(node->right) + 1;
        }
        return ret;
    }
    //功能函数：计算二叉树的高度
    int height(BTreeNode<T>* node) const {
        int ret = 0;
        if(node != nullptr) {
            int lh = height(node->left);
            int rh = height(node->right);
            ret = ((lh > rh) ? lh : rh) + 1;
        }
        return ret;
    }
    //功能函数：计算二叉树的度数
    int degree(BTreeNode<T>* node) const {
        int ret = 0;
        if(node != nullptr) {
            int dl = degree(node->left);
            int dr = degree(node->right);

            ret = (!!node->left + !!node->right);

            if(ret < dl) {
                ret = dl;
            }
            if(ret < dr) {
                ret = dr;
            }
        }
        return ret;
    }
    //功能函数：先序遍历
    void preOrderTraversal(BTreeNode<T>* node) {
        if(node != nullptr) {
            std::cout << node->value << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }
    //功能函数：中序遍历
    void inOrderTraversal(BTreeNode<T>* node) {
        if(node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }
    //功能函数：后序遍历
    void postOrderTraversal(BTreeNode<T>* node) {
        if(node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            std::cout << node->value << " ";
        }
    }
public:
    bool insert(TreeNode<T>* node) {
        return insert(node, ANY);
    }

    bool insert(TreeNode<T>* node, BTNodePos pos) {
        bool ret = true;

        if(node != nullptr) {
            if(this->m_root == nullptr) {
                node->parent = nullptr;
                this->m_root = node;
            } else {
                BTreeNode<T>* np = find(node->parent);
                if(np != nullptr) {
                    ret = insert(dynamic_cast<BTreeNode<T>*>(node), np, pos);
                } else {
                    THROW_EXCEPTION(InvalidParameterException,"cannot find parent tree node..");
                }
            }
        } else {
            THROW_EXCEPTION(InvalidParameterException,"Parameter node can not be nullptr..");
        }

        return ret;
    }

    bool insert(const T& value, TreeNode<T>* parent) {
        return insert(value, parent, ANY);
    }

    bool insert(const T& value, TreeNode<T>* parent, BTNodePos pos) {
        bool ret = true;

        BTreeNode<T>* node = BTreeNode<T>::NewNode();


        if(node == nullptr) {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create new btree node..");
        } else {
            node->value = value;
            node->parent = parent;

            ret = insert(node, pos);

            if(!ret) {
                delete node;
            }
        }
        return ret;
    }

    SharedPointer<Tree<T>> remove(const T& value) {
        BTree<T>* ret = nullptr;

        BTreeNode<T>*node = find(value);

        if(node == nullptr) {
            THROW_EXCEPTION(InvalidParameterException,"cannot find the tree node via value..");
        } else
        {
            Remove(node, ret);
            m_queue.clear();
        }
        return ret;
    }

    SharedPointer<Tree<T>> remove(TreeNode<T>* node)  {
        BTree<T>* ret = nullptr;

        node = find(node);

        if(node == nullptr) {
            THROW_EXCEPTION(InvalidParameterException,"Parameter node is invalid..");
        } else
        {
            Remove(dynamic_cast<BTreeNode<T>*>(node), ret);
            m_queue.clear();
        }
        return ret;
    }

    BTreeNode<T>* find(const T& value) const  {
        return find(root(), value);
    }

    BTreeNode<T>* find(TreeNode<T>* node) const  {
        return find(root(), dynamic_cast<BTreeNode<T>*>(node));
    }

    BTreeNode<T>* root() const  {
        return dynamic_cast<BTreeNode<T>*>(this->m_root);
    }

    int degree() const {
        return degree(root());
    }

    int count() const {
        return count(root());
    }

    int height() const {
        return height(root());
    }

    void clear() {
        free(root());
        m_queue.clear();
        this->m_root = nullptr;
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
            BTreeNode<T>* node = m_queue.front();
            m_queue.remove();
            if(node->left != nullptr) {
                m_queue.add(node->left);
            }
            if(node->right != nullptr) {
                m_queue.add(node->right);
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

    //遍历
    void traversal(BTTraversal order) {

        switch (order) {
            case PreOrder:
                preOrderTraversal(root());
                break;
            case InOrder:
                inOrderTraversal(root());
                break;
            case PostOrder:
                postOrderTraversal(root());
                break;
            default:
                THROW_EXCEPTION(InvalidParameterException,"Parameter order is invalid..");
                break;
        }

    }

    ~BTree() {
        clear();
    }
};
}


#endif //DATASTRUCTURE_REALIZATION_BTREE_H
