
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pSlw, *pHry;
        ListNode res(-1, head);

        pSlw = &res;
        pHry = head;

        while(pHry != nullptr){
            if(n > 0){
                n--;
            }else{
                pSlw = pSlw->next;
            }
            pHry = pHry->next;
        }

        ListNode* temp = pSlw->next;
        pSlw->next = temp->next;
        delete temp;

        return res.next;
    }
};