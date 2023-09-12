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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *ans = nullptr, *cur = ans;
        int carry = 0;
        ListNode *temp1 = new ListNode((carry + p1->val + p2->val) % 10);
        carry = (carry + p1->val + p2->val) / 10;
        p1 = p1->next; 
        p2 = p2->next;
        ans = temp1;
        cur = ans;
        while (p1 || p2) {
            ListNode *temp;
            if (p1 && !p2) {
                temp = new ListNode((carry + p1->val) % 10);
                carry = (carry + p1->val) / 10;
                p1 = p1->next;
                cur->next = temp;
                cur = cur->next;
                cur->next = nullptr;
            }
            else if (!p1 && p2) {
                temp = new ListNode((carry + p2->val) % 10);
                carry = (carry + p2->val) / 10;
                p2 = p2->next;
                cur->next = temp;
                cur = cur->next;
                cur->next = nullptr;
            }
            else {
                temp = new ListNode((carry + p1->val + p2->val) % 10);
                carry = (carry + p1->val + p2->val) / 10;
                p1 = p1->next; 
                p2 = p2->next;
                cur->next = temp;
                cur = cur->next;
                cur->next = nullptr;
            }
        }
        if (carry) {
            temp1 = new ListNode(1);
            cur->next = temp1;
            cur->next->next = nullptr;
        }

        return ans;
    }
};

==============需要注意进位的情况============
小技巧：对于链表问题，返回结果为头结点时，通常需要先初始化一个预先指针 pre，该指针的下一个节点指向真正的头结点 head。使用预先指针的目的在于链表初始化时无可用节点值，而且链表构造过程需要指针移动，进而会导致头指针丢失，无法返回结果。

作者：画手大鹏
链接：https://leetcode.cn/problems/add-two-numbers/solutions/7348/hua-jie-suan-fa-2-liang-shu-xiang-jia-by-guanpengc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

=================a more concise version==========
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;
        while (p1 || p2) {
            int x = p1 ? p1->val : 0;
            int y = p2 ? p2->val : 0;
            int sum = x + y + carry;
            int result = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(result);
            cur->next = temp;
            cur = cur->next;
            cur->next = nullptr;
            if (p1) {
                p1 = p1->next;
            }
            if (p2) {
                p2 = p2->next;
            }
        }
        if (carry) {
            ListNode *temp = new ListNode(1);
            cur->next = temp;
            cur->next->next = nullptr;
        }
        return dummy->next;
    }
};
