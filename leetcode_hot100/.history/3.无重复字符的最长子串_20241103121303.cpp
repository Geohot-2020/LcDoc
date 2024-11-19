/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<string> s_set;
        int res = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            char k = s[r];
            while (s_set.find(k)) {
                s_set.remove(s_set[l]);
                l++;
            }
            s_set.insert(k);

        }
    }
};
// @lc code=end

