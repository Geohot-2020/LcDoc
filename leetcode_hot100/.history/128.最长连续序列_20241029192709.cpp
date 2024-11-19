/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num: nums) {
            num_set.emplace_back(num);
        }

        int maxCount = 0;
        for (const int& num: num_set) {
            if (!num_set.count(num - 1)) {
                int k = num;
                int curCount = 1;
                while (num_set.count(k)) {
                    k++;
                    curCount++;
                }
                maxCount = max(curCount, maxCount);
            }
        }
        return maxCount;
    }
};
// @lc code=end

