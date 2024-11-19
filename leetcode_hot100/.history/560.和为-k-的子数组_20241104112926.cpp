/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int preSum = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            if (mp.count(preSum - k)) {
                ans += mp[preSum - k];
            }
            mp
        }
        return ans;
    }
};
// @lc code=end

