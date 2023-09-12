#include <unordered_set>
using namespace std;

class Solution {
public:  
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for (auto &temp : nums){
            s.insert(temp);
        }
        int max = 0;
        for (auto temp : s) {
            if (s.count(temp - 1)) {
                continue;
            }
            int cur = 0;
            while(s.count(temp++)) {
                cur++;
            }
            if (cur > max) {
                max = cur;
            }
        }
        return max;
    }
};
============above is hashmap========


============below is unionfind======
#include <map>
using namespace std;
class Solution {
private:
    map<int, int> m;
    int find(int x){
        if (m[x] != x) {
            m[x] = find(m[x]);
        }
        return m[x];
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        for (auto temp : nums) {
            m.insert(pair<int, int>(temp, temp));
        }
        for (auto temp : nums) {
            if (m.count(temp + 1)) {
                m[temp] = temp + 1;
            }
        }
        int ans = 0;
        for (auto temp : nums) {
            if (m.count(temp - 1)) {
                continue;
            }
            int cur = find(temp) - temp + 1;
            if (cur > ans) {
                ans = cur;
            }
        }
        return ans;
    }
};



