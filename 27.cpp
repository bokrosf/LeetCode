// https://leetcode.com/problems/remove-element/description/

#include <algorithm>

class Solution 
{
public:
    int removeElement(std::vector<int> &nums, int val) 
    {
        int removed_count = 0;
        size_t i = 0;

        while (i + removed_count < nums.size())
        {
            if (nums[i] == val)
            {
                ++removed_count;
                std::swap(nums[i], nums[nums.size() - removed_count]);
            }

            if (nums[i] != val)
            {
                ++i;
            }
        }

        return nums.size() - removed_count;
    }
};
