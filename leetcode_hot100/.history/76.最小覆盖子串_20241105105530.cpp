/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        string ans=[];
        int left=0;
        unordered_map<char, int> window, need;
        for (char c : t) {
            need[c]++;
        }
        for (int right = 0; right < s.size(); right++;) {
            char c = s[right];
            //1.入。在需要的窗口中，扩
            if (need.find(c) != need.end()) {
                window[]
            }
        }

        return ans;
    }
};
// @lc code=end

