//
// Created by 张永斌 on 2021/4/12.
//

#ifndef DATASTRUCTURE_REALIZATION_TESTTREE_H
#define DATASTRUCTURE_REALIZATION_TESTTREE_H

#include "../HeadCodes/Tree/GTree.h"

namespace DataStructure {
namespace Test {
namespace TreeTest {

void Tree_Test() {
    std::cout << "[===============================================================]\n";
    std::cout << "[----------------- Run DataStructure Test : Tree ---------------]\n";
    std::cout << "[-------------------------- API test ---------------------------]\n";

    GTree<char> t;
    GTreeNode<char>* node = nullptr;

    cout << "Insert a new Tree ." << endl;
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

    cout << "The tree printed from bottom to top : " << endl;


    //t.clear();

    char s1[] = "KLFGMIJ";

    for (int i = 0; i < strlen(s1); ++i) {
        TreeNode<char>* node = t.find(s1[i]);

        while (node != nullptr) {
            cout << node->value << " ";
            node = node->parent;
        }
        cout << endl;
    }

    cout << "Delete node 'D' : " << endl;
    SharedPointer<Tree<char>> p = t.remove('D');
    char s2[] = "KLFGMIJ";
    for (int i = 0; i < strlen(s2); ++i) {
        TreeNode<char>* node = t.find(s2[i]);

        while (node != nullptr) {
            cout << node->value << " ";
            node = node->parent;
        }
        cout << endl;
    }
    cout << "Deleted Tree  : " << endl;
    for (int i = 0; i < strlen(s2); ++i) {
        TreeNode<char>* node = p->find(s2[i]);

        while (node != nullptr) {
            cout << node->value << " ";
            node = node->parent;
        }
        cout << endl;
    }

    std::cout << "The count of the nodes of tree : " << t.count() << std::endl;

    std::cout << "The height of tree : " << t.height() << std::endl;

    std::cout << "The degree of tree : " << t.degree() << std::endl;

    std::cout << "[------------------- Tree Performance Testing ------------------]\n";



}
}
}
}
#endif //DATASTRUCTURE_REALIZATION_TESTTREE_H
