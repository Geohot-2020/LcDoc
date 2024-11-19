/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
                return {it->second, i};
            hashtable[nums[i]] = i;
        }
        return {0};
    }
};
// @lc code=end

