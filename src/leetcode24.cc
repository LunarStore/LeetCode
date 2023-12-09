
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode res;
        ListNode* pRear;
        pRear = &res;
        while(head != nullptr && head->next != nullptr){
            ListNode* fir, *sec;

            fir = head;
            sec = head->next;
            head = sec->next;

            pRear->next = sec;
            sec->next = fir;
            pRear = fir;
        }

        if(head != nullptr){
            pRear->next = head;
            pRear = head;
        }

        pRear->next = nullptr;

        return res.next;
    }
};