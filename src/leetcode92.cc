

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode res(-1, head);
        ListNode* p = &res;
        ListNode *start, *rear;
        int count = 0;
        while(p != nullptr && count <= right) {
            ListNode* temp = p->next;
            if(count + 1 == left){
                start = p;
                rear = start->next;
            }
            if(count >= left) {
                p->next = start->next;
                start->next = p;
            }

            count++;
            p = temp;
        }
        if(rear != nullptr){
            rear->next = p;
        }


        return res.next;
    }
};