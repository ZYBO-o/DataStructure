//
// Created by 张永斌 on 2021/4/12.
//

#ifndef DATASTRUCTURE_REALIZATION_TESTTREE_H
#define DATASTRUCTURE_REALIZATION_TESTTREE_H

#include "../HeadCodes/Tree/GTree.h"
#include "../HeadCodes/Tree/BTree.h"

namespace DataStructure {
namespace Test {
namespace TreeTest {

void Tree_Test() {
    std::cout << "[===============================================================]\n";
    std::cout << "[----------------- Run DataStructure Test : Tree ---------------]\n";
    std::cout << "[----------------------- API GTree test ------------------------]\n";

    GTree<char> t;
    GTreeNode<char>* node = nullptr;

    std::cout << "Insert a new Tree ." <<  std::endl;
    t.insert('A', nullptr);
    node = t.find('A');
    t.insert('B', node);
    t.insert('C', node);
    t.insert('D', node);

    node = t.find('B');
    t.insert('E', node);
    t.insert('F', node);

    node = t.find('E');
    t.insert('K', node);
    t.insert('L', node);

    node = t.find('C');
    t.insert('G', node);

    node = t.find('D');
    t.insert('H', node);
    t.insert('I', node);
    t.insert('J', node);

    node = t.find('H');
    t.insert('M', node);

    std::cout << "The tree printed from bottom to top : " <<  std::endl;


    //t.clear();

    char s1[] = "KLFGMIJ";

    for (int i = 0; i < strlen(s1); ++i) {
        TreeNode<char>* node = t.find(s1[i]);

        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->parent;
        }
        std::cout <<  std::endl;
    }

    std::cout << "Level traversal of the tree : " ;

    for (t.begin(); !t.end(); t.next()) {
        std::cout << t.current() << " " ;
    }
    std::cout << std::endl;

    std::cout << "Delete node 'D' : " <<  std::endl;
    SharedPointer<Tree<char>> p = t.remove('D');
    char s2[] = "KLFGMIJ";
    for (int i = 0; i < strlen(s2); ++i) {
        TreeNode<char>* node = t.find(s2[i]);

        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->parent;
        }
        std::cout <<  std::endl;
    }


    std::cout << "Deleted Tree  : " <<  std::endl;
    for (int i = 0; i < strlen(s2); ++i) {
        TreeNode<char>* node = p->find(s2[i]);

        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->parent;
        }
        std::cout << endl;
    }

    std::cout << "The count of the nodes of tree : " << t.count() << std::endl;

    std::cout << "The height of tree : " << t.height() << std::endl;

    std::cout << "The degree of tree : " << t.degree() << std::endl;

    std::cout << "Level traversal of the tree after deleting : " ;

    for (t.begin(); !t.end(); t.next()) {
        std::cout << t.current() << " " ;
    }
    std::cout << std::endl;

    std::cout << "[------------------- BTree Performance Testing ------------------]\n";
    std::cout << "[----------------------- API GTree test ------------------------]\n";

    BTree<int> bt;
    BTreeNode<int>* n = nullptr;

    std::cout << "Insert a new BTree ." <<  std::endl;

    bt.insert(1, nullptr);

    n = bt.find(1);
    bt.insert(2,n);
    bt.insert(3,n);

    n = bt.find(2);
    bt.insert(4,n);
    bt.insert(5,n);

    n = bt.find(4);
    bt.insert(8,n);
    bt.insert(9,n);

    n = bt.find(5);
    bt.insert(10,n);

    n = bt.find(3);
    bt.insert(6,n);
    bt.insert(7,n);

    n = bt.find(6);
    bt.insert(11,n, LEFT);

    std::cout << "Level traversal of the BTree  : " ;

    for (bt.begin(); !bt.end(); bt.next()) {
        std::cout << bt.current() << " " ;
    }

    std::cout << std::endl;

    std::cout << "The count of the nodes of BTree : " << bt.count() << std::endl;

    std::cout << "The height of BTree : " << bt.height() << std::endl;

    std::cout << "The degree of BTree : " << bt.degree() << std::endl;

    std::cout << "The tree printed from bottom to top : " <<  std::endl;
    int a[] = {8, 9, 10, 11, 7};

    for (int i = 0; i < sizeof(a)/sizeof (a[0]); ++i) {
        TreeNode<int>* node = bt.find(a[i]);
        while (node) {
            std::cout << node->value << " ";
            node = node->parent;
        }
        std::cout<< std::endl;
    }

    std::cout << "The BTTree preOrderTraversal  : " <<  std::endl;
    bt.traversal(PreOrder);
    std::cout << std::endl;

    std::cout << "The BTTree inOrderTraversal  : " <<  std::endl;
    bt.traversal(InOrder);
    std::cout << std::endl;

    std::cout << "The BTTree postOrderTraversal  : " <<  std::endl;
    bt.traversal(PostOrder);
    std::cout << std::endl;

    std::cout << "Remove BTree node 3 : " << std::endl;
    SharedPointer<Tree<int>> sp = bt.remove(3);
    for (int i = 0; i < sizeof(a)/sizeof (a[0]); ++i) {
        TreeNode<int>* node = bt.find(a[i]);
        while (node) {
            std::cout << node->value << " ";
            node = node->parent;
        }
        std::cout<< std::endl;
    }

    std::cout << "Removed BTree : " << std::endl;

    for (int i = 0; i < sizeof(a)/sizeof (a[0]); ++i) {
        TreeNode<int>* node = sp->find(a[i]);
        while (node) {
            std::cout << node->value << " ";
            node = node->parent;
        }
        std::cout<< std::endl;
    }


    std::cout<< "Clean the BTree ." << std::endl;
    bt.clear();
    if(bt.root() == nullptr) {
        std::cout << "BTree has been cleaned" << std::endl;
    }


    std::cout << "[------------------- BTree Performance Testing ------------------]\n";





}
}
}
}
#endif //DATASTRUCTURE_REALIZATION_TESTTREE_H
