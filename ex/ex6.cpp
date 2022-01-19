

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur)    {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

void printList(ListNode *node){
    while (node)   {
        std::cout << node->val << "\t";
        node = node->next;
    }
    std::cout << "------------" << std::endl;
}
int main(){
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    printList(head);

    head = reverseList(head);
    printList(head);
    return 0;
}