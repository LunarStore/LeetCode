
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* begin, ListNode* end){
        ListNode res;

        while(begin != end){
            ListNode* temp = begin->next;
            begin->next = res.next;
            res.next = begin;

            begin = temp;
        }

        return res.next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode res, *pRear;
        ListNode* end;
        int count = 0;
        end = head;
        pRear = &res;
        while(end != nullptr || count == k){
            if(count < k){
                count++;
                end = end->next;
            }else{
                ListNode* nextRear = head;
                pRear->next = reverse(head, end);
                pRear = nextRear;

                head = end;
                count = 0;
            }
        }

        pRear->next = head;

        return res.next;
    }
};