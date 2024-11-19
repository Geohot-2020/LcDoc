/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                int j = i + 1;
                while (nums[j] == 0) {
                    j++;
                }
                nums[i] = nums[j];
                nums[j] = 0;
            }

        }
    }
};
// @lc code=end

