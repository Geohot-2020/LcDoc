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
        for (char c : s) {
            need[c]++;
        }
        for (int l = 0, r = 0; r < s.size(); r++) {
            char c = s[r];
            if (need.count(c)) {
                window[c]++;
            }

        }
};
// @lc code=end

