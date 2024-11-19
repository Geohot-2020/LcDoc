/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
public:
    int hIndex(vector<int>& citations) {
        int curIndex = 
    }
};
// @lc code=end

