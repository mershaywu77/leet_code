// @algorithm @lc id=838 lang=cpp 
// @title design-linked-list
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};


class MyLinkedList {
private:
    ListNode* head;
    ListNode* dummy_head;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        dummy_head = new ListNode(-1, head);
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode* tmp = head;
        while (index--) {
            tmp = tmp->next;
        }
        return (tmp->val);
    }
    
    void addAtHead(int val) {
        ListNode* tmp = head;
        head = new ListNode(val, tmp);
        dummy_head->next = head;
        ++size;
        return;
    }
    
    void addAtTail(int val) {
        ListNode* tmp = dummy_head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new ListNode(val);
        head = dummy_head->next;
        ++size;
        return;
    }
    
    void addAtIndex(int index, int val) {
        if (index == size) {
            addAtTail(val);
        } else if (index >= 0 && index < size) {
            ListNode* tmp = dummy_head;
            while (index--) {
                tmp = tmp->next;
            }
            ListNode* n = tmp->next;
            tmp->next = new ListNode(val, n);
            head = dummy_head->next;
            ++size;
        }
        return;
    }
    
    void deleteAtIndex(int index) {
        if (index >= 0 && index < size) {
            ListNode* tmp = dummy_head;
            while (index--) {
                tmp = tmp->next;
            }
            ListNode* n = tmp->next;
            tmp->next = tmp->next->next;
            head = dummy_head->next;
            delete n;
            --size;
        }
    }
};


int main() {
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(0);
    cout << param_1 << endl;
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    int param_2 = obj->get(1);
    obj->deleteAtIndex(0);
    int param_3 = obj->get(0);
}