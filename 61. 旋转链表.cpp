#include"headFile.h"
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* p=head;
        int n = 1;
        while (p->next != NULL) {
            p = p->next;
            n++;
        }
        p->next = head;
        int add = n - k % n;
        if (add == n) {
            return head;
        }
        while (add--)
        {
            p = p->next;
        }
        ListNode* res = p->next;
        p->next = NULL;
        return res;
    }
};