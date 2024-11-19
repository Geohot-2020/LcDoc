/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (char c : p) {
            need[c]++;
        }
        vector<int> ans;
        int l = 0, r = 0;
        int valid = 0;

        while (r < s.size()) {
            char c = s[r];
            r++;
            if (need.count[c]) {
                
            }
        }
    }
};
// @lc code=end

