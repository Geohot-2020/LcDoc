/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            n++;
        }
        ListNode* p0 = &dummy;
        while (n >= k) {
            n -= k;
            ListNode* pre = nullptr;
            ListNode* cur = p0->next;
            for (int i = 0; i < k; i++) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur->next = nxt;
            }
            p0->next->next = cur;
            p0->next = pre;
        }
    }
};
// @lc code=end

