// 注意链表遍历时的循环判断条件是fast && fast->next
// 针对不同长度的链表，尤其是偶数长度
// 若需要中间靠后一个元素，则判断条件是fast && fast->next
// 若需要中间靠前一个元素，则判断条件是fast->next && fast->next->next
// 对于后一种情况，也可以让fast先走两步实现


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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        }
        return slow;
    }
};
