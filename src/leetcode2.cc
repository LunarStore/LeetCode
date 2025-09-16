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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 链表指针操作
        // list: 低位 -> 高位
        int spill = 0;
        ListNode* res = nullptr;
        ListNode** cur = &res;
        while (l1 || l2) {
            int temp = spill;
            if (l1) {
                temp += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            }

            *cur = new ListNode(temp % 10);
            cur = &(*cur)->next;

            spill = temp / 10;
        }

        if (spill) {
            *cur = new ListNode(spill);
            cur = &(*cur)->next;
        }
        return res;
    }
};

int main() {

    cout << "hello" << endl;
    return 0;
}