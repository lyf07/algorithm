class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        bool flag = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next) {
                fast = fast->next;
            }
            else {
                break;
            }
            if (fast == slow) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            return nullptr;
        }
        else {
            fast = head;
            while (fast != slow) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return fast;
    }
};
=========== above is the original version ================

=========== below is the newest, better version ==============
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (true) {
            if (!fast || !fast->next) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = head;
                break;
            }
        }
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
