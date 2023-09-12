========我愿称之为滑动窗口之最基础的题目======

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> store(26);
        vector<int> stable(26);
        if (s.size() < p.size()) {
            return vector<int>();
        }
        for (int i = 0; i < p.size(); i++) {
            store[s[i] - 'a']++;
            stable[p[i] - 'a']++;
        }
        
        if (store == stable) {
            ans.push_back(0);
        }
        for (int i = 0; i < s.size() - p.size(); i++) {
            store[s[i] - 'a']--;
            store[s[i + p.size()] - 'a']++;
            if (store == stable) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};


