class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return head;
        }
        ListNode *cur = head, *after = head->next, *ret = after;
        while (true) {
            ListNode *n = after->next;
            after->next = cur;
//            cur->next = n;
//            cur = n;
            if (!n) {
                cur->next = nullptr;
                break;
            }
            if (!n->next) {
                cur->next = n;
                break;
            }
            cur->next = n->next;
            cur = n;
            after = cur->next;
        }
        return ret;
    }
};
================ above is the older uglier version =============

================ below is the newer better version(iteration version) =============
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            ListNode *after = cur->next;
            ListNode *nafter = after->next;
            ListNode *nnafter = nafter->next;
            nafter->next = after;
            after->next = nnafter;
            cur->next = nafter;
            cur = after;
        }
        return dummy->next;
    }
};

================== below is a concise recursive version =================
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return head;
        }
        ListNode *cur = head, *after = head->next;
        ListNode *n = after->next;
        after->next = cur;
        cur->next = swapPairs(n);
        return after;
    }
};
