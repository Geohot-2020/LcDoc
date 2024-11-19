/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        int ;
        while (left < n) {
            if (nums[left] == 0) {
                while (nums[right] == 0)
                    right ++;
            }
        }
    }
};
// @lc code=end

