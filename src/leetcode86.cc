struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode little, great;
        ListNode *littleRear, *greatRear;
        littleRear = &little;
        greatRear = &great;
        
        while(head != nullptr) {
            if(head->val < x) {
                littleRear->next = head;
                littleRear = head;
            } else {
                greatRear->next = head;
                greatRear = head;
            }

            head = head->next;
        }
        greatRear->next = nullptr;
        littleRear->next = great.next;
        return little.next;
    }
};