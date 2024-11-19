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
        while (fast < n) {
            // 交换，如果全是非0，全自己和自己交换
            // 如果有0，则快指针先走一步，慢指针是0
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        while (slow < n) {
            nums[slow++] = 0;
        }
    }
};
// @lc code=end

