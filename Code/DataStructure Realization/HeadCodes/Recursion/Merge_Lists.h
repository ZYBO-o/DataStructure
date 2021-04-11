//
// Created by 张永斌 on 2021/4/6.
//

#ifndef DATASTRUCTURE_REALIZATION_MERGE_LISTS_H
#define DATASTRUCTURE_REALIZATION_MERGE_LISTS_H

#include "List_Case.h"

class Solution {
public:
    ListNode* Merge(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;
        else if(list1->val < list2->val) {
            ListNode* list1_ = list1->next;
            ListNode* list = Merge(list1_, list2);
            list1->next = list;
            return list1;
        } else {
            ListNode* list2_ = list2->next;
            ListNode* list = Merge(list1, list2_);
            list2->next = list;
            return list2;
        }
    }
};

void Test() {
    vector<int> num1 {1,2,3,4,5,6};
    vector<int> num2 {3,4,5,6,7,8};

    ListNode* list1 = Create(num1);
    ListNode* list2 = Create(num2);

    Print(list1);
    Print(list2);

    Solution solution;
    ListNode* list = solution.Merge(list1, list2);
    Print(list);

}

#endif //DATASTRUCTURE_REALIZATION_MERGE_LISTS_H
