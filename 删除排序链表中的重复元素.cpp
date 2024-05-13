#include"headFile.h"
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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* p = head;
        ListNode* q = head->next;
        while (q != nullptr) {
            if (q->val != p->val) {
                ListNode* Delete = p->next;
                p->next = q;
                p = q;
            }
            else {
                p->next = nullptr;
            }
            q = q->next;
        }
        return head;
    }
};