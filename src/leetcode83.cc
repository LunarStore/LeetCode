#include <iostream>

using namespace std;
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
        ListNode h(INT_MIN);
        ListNode* rear, *p = head;
        rear = &h;

        while(p != nullptr){
            ListNode* next = p->next;
            if(p->val != rear->val){
                rear->next = p;
                rear = p;
            }else{
                delete p;
            }
            p = next;
        }

        rear->next = nullptr;

        return h.next;
    }
};