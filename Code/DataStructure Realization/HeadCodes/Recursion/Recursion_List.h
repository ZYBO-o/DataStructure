//
// Created by 张永斌 on 2021/4/6.
//

#ifndef DATASTRUCTURE_REALIZATION_RECURSION_LIST_H
#define DATASTRUCTURE_REALIZATION_RECURSION_LIST_H

#include "List_Case.h"

//反转链表
class Solution {
public:
    ListNode* Reverse(ListNode* list) {
        if(list == nullptr || list->next == nullptr) {
            return list;
        } else {
            //递归操作
            ListNode* guard = list->next;
            ListNode* ret = Reverse(list->next);
            guard->next = list;
            list->next = nullptr;
            return ret;
        }
    }
};

void Test() {
    vector<int> nums {1,2,3,4,5};
    ListNode* list = Create(nums);
    Print(list);
    Solution solution;
    list = solution.Reverse(list);
    Print(list);
}

#endif //DATASTRUCTURE_REALIZATION_RECURSION_LIST_H
