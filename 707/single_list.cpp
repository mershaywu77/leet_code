class MyLinkedList {
private:
    int val;
    MyLinkedList* next;    
public:
    MyLinkedList() : val(0), next(nullptr) {

    }
    MyLinkedList(int x) : val(x), next(nullptr) {

    }
    
    int get(int index) {
        MyLinkedList* cur = this; //pre
        int i;
        for (i = 0; i < index + 1 && cur; ++i) 
        {
            cur = cur->next;
        }
        if (cur) // in scope
        {
            return cur->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        MyLinkedList* head = new MyLinkedList(val);
        head->next = next;
        next = head;
    }
    
    void addAtTail(int val) {
        MyLinkedList* cur = this;
        while(cur && cur->next)
            cur = cur->next;
        MyLinkedList* pNode = new MyLinkedList(val);
        cur->next = pNode;
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedList* cur = this; //pre
        int i;
        for (i = 0; i < index && cur; ++i) 
        {
            cur = cur->next;
        }
        if (i == index && cur) // in scope
        {
            MyLinkedList* pNode = new MyLinkedList(val);
            pNode->next = cur->next;
            cur->next = pNode;
        }
    }
    
    void deleteAtIndex(int index) {
        MyLinkedList* cur = this; //pre
        int i;
        for (i = 0; i < index && cur; ++i) 
        {
            cur = cur->next;
        }   
        if (index == i && cur && cur->next) // in scope
        {
            MyLinkedList* pNode = cur->next;
            cur->next = pNode->next;
            delete pNode;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */