/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
        }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start, end;
        start = lower_bound(nums, target);
        if (start == nums.size() || )
        ans.push_back();
        ans.push_back(lower_bound(nums, target + 1) -1 );
        return ans;
    }
};
// @lc code=end

