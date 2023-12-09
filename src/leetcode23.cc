#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//优先队列或者分治
class Solution {
    struct Cmp{
        bool operator () (const ListNode* a, const ListNode*  b){
            return a->val > b->val;		
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pqueue;
        ListNode res, *pRear;
        pRear = &res;
        for(auto& it : lists){
            if(it == nullptr) continue;
            pqueue.push(it);
        }

        while(pqueue.empty() == false){
            ListNode* curMin = pqueue.top();
            pqueue.pop();
            pRear->next = curMin;
            pRear = curMin;
            curMin = curMin->next;
            if(curMin != nullptr){
                pqueue.push(curMin);
            }
        }

        pRear->next = nullptr;

        return res.next;
    }
};

int main(){

    return 0;
}