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
 #include <vector>
 using namespace std;
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return;
        ListNode *p = head;
        vector<ListNode*> v;
        while (p) {
            v.push_back(p);
            p = p->next;
        }
        int n = v.size();
        int i = 0, j = n - 1;
        while (i < j) {
            v[i]->next = v[j];
            i++;
            if (i == j) {
                break;
            }
            v[j]->next = v[i];
            j--;
        }
        v[i]->next = nullptr;
    }
};


--------a greater version is above--------


--------first bad version------
class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode *> d;
        ListNode *p = head;
        while (p) {
            d.push_back(p);
            p = p->next;
        }
        ListNode *f = nullptr, *b = nullptr, *rec = nullptr;
        while (!d.empty()) {
            f = d.front();
            d.pop_front();
            if (d.empty()) {
                if(rec)
                    rec->next = f;
                f->next = nullptr;
                break;
            }
            if (rec){
                rec->next = f;
            }
            b = d.back();
            d.pop_back();
//            if (!d.empty()){
//                f->next = b;
//            }
//            else {
//                f->next = nullptr;
//                break;
//            }
            f->next = b;
            b->next = nullptr;
            rec = b;
        }
    }
};

