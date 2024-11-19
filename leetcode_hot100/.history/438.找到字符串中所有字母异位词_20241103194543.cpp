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
        int valid = 0;
        for (char c : s) {
            need[c]++;
        }
        for (int l = 0, r = 0; r < s.size(); r++) {
            char c = s[r];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (r - l >= p.size()) {
                if (valid == need.size())
                    res.push_back(l);
                char d = s[l];
                l++;
                if (need.count[d]) {
                    if ()
                }
            }

        }
};
// @lc code=end

