/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int h = citations.size() - mid;
            if (citations[mid] < h) left = mid + 1;
            else right = mid - 1;
        }
        return left;
        
    }
};
// @lc code=end

