/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower_bound(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid])
            }
        }
    }
};
// @lc code=end

