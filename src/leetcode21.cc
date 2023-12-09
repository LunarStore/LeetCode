
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode res, *pRear;
        pRear = &res;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                pRear->next = list1;
                list1 = list1->next;
            }else{
                pRear->next = list2;
                list2 = list2->next;
            }
            pRear = pRear->next;
        }

        if(list1 != nullptr) pRear->next = list1;
        if(list2 != nullptr) pRear->next = list2;

        return res.next;
    }
};
