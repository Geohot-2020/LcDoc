/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;   //双端队列
        for (int i = 0; i < nums.size(); i++) {
            // 1.入
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();   //维护q单调性
            }
            q.push_back(i);
            // 2.出
            if (i - q.front() > k) {
                q.pop_front();
            }
            if (i >= k-1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
// @lc code=end

