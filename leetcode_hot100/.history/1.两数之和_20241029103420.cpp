/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashTable.find(target - nums[i]);
            if (it != hashTable.end())
                return {i, it.second};
            hashTable[nums[i]] = i;
        }
        return;
    }
};
// @lc code=end

