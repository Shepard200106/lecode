#include<iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* num = head;
        int n = 0;
        while (num != NULL) {
            n++;
            num = num->next;
        }
        if (n < k) {
            return head;
        }
        ListNode* ans = new ListNode();
        ListNode* p = ans;
        ListNode* q = ans;
        num = head;
        int i = 0;
        while (num!=NULL) {
            if (n < k) {
                q->next = num;
                break;
            }
            ListNode* t = new ListNode(num->val);
            t->next = p->next;
            p->next = t;
            if (q->next != nullptr) {
                q = q->next;
            }
            num = num->next;
            i++;
            if (i % k == 0) {
                n = n - k;
                p = q;
            }
        }
        return ans->next;
    }
};

/*class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0), *pre = &dummy, *next, *cur = pre;
        pre->next = head;
        int len = 0;
        while (cur = cur->next) ++len; // ��������ڵ���������ȣ�
        while (len >= k) { // ���� ���𳵡�
            cur = pre->next, next = cur->next;
            for (int i = 1; i < k; ++i) { // ���� �����䡱
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next, next = cur->next;
            }
            pre = cur, len -= k; // �����½� �����䡱
        }
        return dummy.next; // ���ص�һ�ڳ���ĳ�ͷ
    }
};

���ߣ�����
���ӣ�https://leetcode.cn/problems/reverse-nodes-in-k-group/solutions/829877/5fen-dai-ma-ji-jian-cdai-ma-by-fengziluo-ucsi/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/