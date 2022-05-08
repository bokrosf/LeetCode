/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

/// <summary>
/// https://leetcode.com/problems/add-two-numbers/
/// </summary>
public class Solution
{
    public ListNode AddTwoNumbers(ListNode firstList, ListNode secondList)
    {
        int carried = 0;
        ListNode addedList = new ListNode();
        ListNode startOfResult = addedList;

        while (firstList != null || secondList != null)
        {
            int sum = (firstList?.val ?? 0) + (secondList?.val ?? 0) + carried;
            addedList.val = sum % 10;
            carried = sum > 9 ? 1 : 0;

            if (firstList?.next != null || secondList?.next != null)
            {
                addedList.next = new ListNode();
                addedList = addedList.next;
            }

            firstList = firstList?.next;
            secondList = secondList?.next;
        }

        if (carried > 0)
        {
            addedList.next = new ListNode(carried);
        }

        return startOfResult;
    }
}