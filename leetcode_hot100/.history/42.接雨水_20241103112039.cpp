/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        st.push(0);
        for (int i = 0; i < height.size(); i++) {
            if (height[i] < height[st.top()])   
        }
    }
};
// @lc code=end

