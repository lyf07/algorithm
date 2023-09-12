/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        int len = 0;
        ListNode *p = head;
        while (p) {
            p = p->next;
            len++;
        }
        k = k % len;
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        ListNode *ans = slow->next;
        slow->next = nullptr;
        return ans;
    }
};
=========相当于找到倒数第k个链表节点的升级版=============
