/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int cnt[26]{};
        for (char c : p) 
            cnt[c - 'a']++;
        for (int l = 0, r = 0; r < s.size(); r++) {
            char c = s[r];
            cnt[c - 'a']--;

        }
    }
};
// @lc code=end

