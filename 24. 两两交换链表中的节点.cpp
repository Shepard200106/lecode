#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)return head;
        ListNode* firstNode = head;
        ListNode* secNode = head->next;
        firstNode->next = swapPairs(secNode->next);
        secNode->next = firstNode;
        return secNode;
    }
};