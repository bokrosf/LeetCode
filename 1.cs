using System.Collections.Generic;

namespace LeetCode;

/// <summary>
/// https://leetcode.com/problems/two-sum/
/// </summary>
public class Solution
{
    class IndexRegistry
    {
        public int FirstIndex { get; set; }
        public int? LastIndex { get; set; }
    }

    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, IndexRegistry> indeces = GetNumberIndeces(nums);

        for (int i = 0; i < nums.Length; i++)
        {
            int difference = target - nums[i];

            if (indeces.TryGetValue(difference, out var registry))
            {
                if (difference == nums[i] && registry.LastIndex.HasValue)
                {
                    return new int[] { i, registry.LastIndex.Value };
                }
                else if (difference != nums[i])
                {
                    return new int[] { i, registry.FirstIndex };
                }
            }
        }

        return new int[2];
    }

    private Dictionary<int, IndexRegistry> GetNumberIndeces(int[] nums)
    {
        Dictionary<int, IndexRegistry> indeces = new(nums.Length);

        for (int i = 0; i < nums.Length; i++)
        {
            if (indeces.TryGetValue(nums[i], out var registry))
            {
                registry.LastIndex = i;
            }
            else
            {
                indeces[nums[i]] = new IndexRegistry { FirstIndex = i, LastIndex = null };
            }
        }

        return indeces;
    }
}
