/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int left = 0, right = numbers.size() - 1;
        int curSum;
        while (left < right) {
            curSum = numbers[left] + numbers[right];
            if (curSum > target)    right--;
            else if (curSum < target)   left++;
            else {
                return {left, right};
            }
        }
        return ans;
        
        //return ans;
    }
};
// @lc code=end

