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
        vector<int> res;
        int valid = 0;
        for (char c : p) {
            need[c]++;
        }
        for (int l = 0, r = 0; r < s.size(); r++) {
            char c = s[r];
            // 包含在里面,则+1
            if (need.count(c)) {
                window[c]++;
                // 和所求相等
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (r - l + 1 >= p.size()) {
                if (valid == need.size())
                    res.push_back(l);
                char d = s[l];
                l++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

