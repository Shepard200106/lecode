#include<iostream>
#include<stack>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* p = head;
        ListNode* q = head;
        while (q!=nullptr) {
            length+=1;
            q = q->next;
        }
        if (n>length) {
            return head;
        }
        int i = 0;
        int x = length - n;
        if (x == 0) {
            ListNode* res = head->next;
            return res;
        }
        while (i<x-1) {
            p = p->next;
            i++;
        }
        q = p->next;            //¿ªÊ¼É¾³ý²Ù×÷
        p->next = q->next;
        delete q;
        return head;
    }
};