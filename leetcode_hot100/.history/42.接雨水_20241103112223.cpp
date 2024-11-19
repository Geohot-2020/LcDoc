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
            // 递增栈
            if (height[i] < height[st.top()])   st.push(i);
            else if (height[i] == height[st.top()]) st.push(i);
            else {
                while (!st.empty() && height[i] > height[st.top]) {
                    int mid = st.pop();
                }
            }
        }
    }
};
// @lc code=end

