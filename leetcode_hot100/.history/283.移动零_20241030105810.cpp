/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        int n = nums.size();
        while (slow < n) {
            if (nums[fast])
                slow++;
            fast++;
        }
    }
};
// @lc code=end

