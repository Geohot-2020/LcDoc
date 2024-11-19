/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].em
        }
        vector<vector<string>> ans;

    }
};
// @lc code=end

