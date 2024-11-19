/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int left, right;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (num[i] > 0) return {};
            if (i > 0 && nums[i] == nums[i-1]) continue;
            left = i + 1;
            right = n -1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    res.push_back(nums)
                }
            }
        }
    }
};
// @lc code=end

