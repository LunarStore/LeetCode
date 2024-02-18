
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int listLen = 0;
        ListNode** p = &head;
        ListNode* res = nullptr;
        if(head == nullptr) return nullptr;
        while(*p != nullptr){
            listLen++;
            p = &(*p)->next;
        }
        *p = head;  // 成环
        k = k % listLen;
        int pos = listLen - k;

        for(int i = 1; i < pos; i++){
            head = head->next;
        }
        res = head->next;
        head->next = nullptr;
        return res;
    }
};