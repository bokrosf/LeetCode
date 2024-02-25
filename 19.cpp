// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution 
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int i = 1;
        ListNode *current = head;

        while (i <= n && current->next)
        {
            current = current->next;
            ++i;
        }

        if (i > n && !curren)
        {
            return head->next;
        }

        ListNode *before_removed = head;

        while (current->next)
        {
            current = current->next;
            before_removed = before_removed->next;
        }

        if (!before_removed->next)
        {
            return nullptr;
        }

        before_removed->next = before_removed->next->next;

        return head;
    }
};
