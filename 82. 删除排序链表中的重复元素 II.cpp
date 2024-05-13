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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* current = head;
        while (current != nullptr) {
            bool isDuplicate = false;
            while (current->next != nullptr && current->val == current->next->val) {
                isDuplicate = true;
                ListNode* temp = current;
                current = current->next;
                delete temp;
            }
            if (isDuplicate) {
                ListNode* temp = current;
                current = current->next;
                delete temp;
            }
            else {
                pre->next = current;
                pre = current;
                current = current->next;
            }
        }
        pre->next = nullptr;
        return dummy->next;
    }
};