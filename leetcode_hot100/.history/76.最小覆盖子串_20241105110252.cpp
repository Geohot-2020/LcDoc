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
        int start = 0, len = INT_MAX;
        int left = 0, valid = 0;
        unordered_map<char, int> window, need;
        for (char c : t) {
            need[c]++;
        }
        for (int right = 0; right < s.size(); right++;) {
            char c = s[right];
            //1.入。在需要的窗口中，扩
            if (need.find(c) != need.end()) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            //2.出。窗口值完全覆盖
            while (valid == need.size()) {
                // 3.记。更新最小字串
                if (len > right - left + 1) {
                    start = left;
                    len = right - left + 1;
                }
                //出
                char d = window[left];
                if (need.find(d) != need.end()) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
                left++;
            }
        }
        ans = len==INT_MAX s.substr(start, len);
        return ans;
    }
};
// @lc code=end

