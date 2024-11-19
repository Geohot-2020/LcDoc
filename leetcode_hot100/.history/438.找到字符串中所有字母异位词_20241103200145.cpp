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
                // 和所求相等,ok
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            // 边界条件,窗口>=字符串p长度
            while (r - l + 1 >= p.size()) {
                // 当前窗口为字母异位
                if (valid == need.size())
                    res.push_back(l);
                // 滑出
                char d = s[l];
                l++;
                // 包含在里面
                if (need.count(d)) {
                    //window中与need相同,-1
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

