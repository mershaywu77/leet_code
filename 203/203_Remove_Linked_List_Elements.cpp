// @algorithm @lc id=203 lang=cpp 
// @title remove-linked-list-elements


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,6,3,4,5,6],6)=[1,2,3,4,5]
// @test([],1)=[]
// @test([7,7,7,7],7)=[]
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy_head = new ListNode(-1, head);
        ListNode* tmp = dummy_head;
        while ((tmp != nullptr) && 
               (tmp->next != nullptr)) {
            if (tmp->next->val == val) {
                ListNode* n = tmp->next;
                tmp->next = tmp->next->next;
                delete n;
            } else {
                tmp = tmp->next;
            }
        }
        tmp = dummy_head->next;
        return tmp;
    }
};