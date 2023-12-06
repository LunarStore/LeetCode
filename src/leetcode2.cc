
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode res;
        ListNode *pCur = &res;
        int spill = 0;
        while(l1 != nullptr || l2 != nullptr || spill != 0){
            int sum = spill;

            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            spill = sum / 10;

            ListNode* temp = new ListNode(sum % 10);
            pCur->next = temp;
            pCur = temp;
        }

        pCur->next = nullptr;
        return res.next;
    }
};