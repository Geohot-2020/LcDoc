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
            // s[j]
            preSum += nums[i];
            // 存在s[i] == s[j] - k个数
            if (mp.count(preSum - k)) {
                // 结果
                ans += mp[preSum - k];
            }
            // s[j]个数+1
            mp[preSum]++;
        }
        return ans;
    }
};
// @lc code=end

