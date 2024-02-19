
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** rear = &head;
        ListNode* p = head;

        while(p != nullptr){
            ListNode* next = p->next;
            while(next != nullptr && next->val == p->val){  // 找到下一个不同元素
                ListNode* n = next->next;
                delete next;
                next = n;
            }

            if(p->next == next){
                *rear = p;
                rear = &(p->next);
            }else{
                delete p;
            }

            p = next;
        }
        *rear = nullptr;
        return head;
    }
};