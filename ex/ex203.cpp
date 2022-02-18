

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while(cur->next){
            if(cur->next->val == val){
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    ListNode *head = nullptr;
    for (int i = 6; i > 0; i--)
    {
        ListNode * node = new ListNode(i, head);
        head = node;
    }
    Solution s;
    s.removeElements(head, 6);
    return 0;
}