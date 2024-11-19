/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start
class Solution {
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
public:
    int maximumCount(vector<int>& nums) {
        int start = 0, end = 0;
        start = lower_bound(nums, 0) - nums.begin();
        end = nums.end() - lower_bound(nums, 0)
    }
};
// @lc code=end

