/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int curVol, maxVol=0;
        while (l < r) {
            curVol = (r - l) * min(height[l], height[r]);
            maxVol = max(curVol, maxVol);
            if (height[l] < height[r])
                l++;
            else 
                r++;
        }
        return maxVol;
    }
};
// @lc code=end

