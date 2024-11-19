/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        // int slow = 0, fast = 1;
        // int n = height.size();
        // int curVol, maxVol = 0;
        // while (slow < n - 1) {
        //     fast = slow + 1;
        //     while (fast < n) {
        //         curVol = (fast - slow) * min(height[slow], height[fast]);
        //         maxVol = max(curVol, maxVol);
        //         fast++;
        //     }
        //     slow++;
        // }
        // return maxVol;
        int n = height.size();
        int l = 0, r = n-1;
        int curVol, maxVol=0;
        while (l < r) {
            curVol = (r - l) * min(height[l], height[r]);
            maxVol = max(curVol, maxVol);
            if (l < r)
        }
    }
};
// @lc code=end

