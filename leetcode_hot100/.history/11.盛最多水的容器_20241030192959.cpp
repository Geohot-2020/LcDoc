/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int slow = 0, fast = 1;
        int n = height.size();
        int curVol, maxVol = 0;
        while (slow < n - 1) {
            fast = slow + 1;
            while (fast < n) {
                curVol = (fast - slow) * min(height[slow], height[fast]);
                maxVol = max(curVol, maxVol);
            }
            slow++;
        }
        return maxVol;
    }
};
// @lc code=end

