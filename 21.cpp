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
class Solution 
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) 
    {
        if (!list1)
        {
            return list2;
        }    

        if (!list2)
        {
            return list1;
        }

        ListNode **lower_head = list1->val <= list2->val ? &list1 : &list2;
        ListNode *merged_head = *lower_head;
        *lower_head = (*lower_head)->next;
        ListNode *merged_last = merged_head;
        
        while (list1 && list2)
        {
            ListNode **merged_node = list1->val <= list2->val ? &list1 : &list2;
            merged_last->next = *merged_node;
            merged_last = merged_last->next;
            *merged_node = (*merged_node)->next;
        }

        merged_last->next = list1 ? list1 : list2;

        return merged_head;
    }
};
