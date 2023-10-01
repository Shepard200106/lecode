#include<iostream>
#include<vector>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        int i = 0;
        if (n == 0)return{};
        ListNode* p1 = lists[0];
        ListNode* p2 = lists[1];
        while(i < n - 1){
            ListNode* t = new ListNode();
            ListNode* t1 = t;
            while (p1 != nullptr && p2 != nullptr) {
                if (p1->val < p2->val) {
                    t1->next = p1;
                    p1 = p1->next;
                }
                else {
                    t1->next = p2;
                    p2 = p2->next;
                }
                t1 = t1->next;
            }
            t1->next = p1 != nullptr ? p1 : p2;
            p1 = t->next;
            i++;
            if(i+1<lists.size())p2 = lists[i + 1];
        }
        return p1;
    }
};