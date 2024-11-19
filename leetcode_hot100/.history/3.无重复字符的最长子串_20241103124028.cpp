/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> s_set;
        int res = 0;
        // 外圈右边界，内圈左边界
        for (int l = 0, r = 0; r < s.size(); r++) {
            char k = s[r];  //当前考虑元素
            while (s_set.find(k) != s_set.end()) {  
                s_set.erase(s[l]);
                l++;
            }
            s_set.insert(k);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end

