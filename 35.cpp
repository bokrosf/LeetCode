// https://leetcode.com/problems/search-insert-position/description/

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target) 
    {
        int begin = 0;
        int end = nums.size() - 1;
        int i = begin + (end - begin) / 2;

        while (begin <= end && nums[i] != target)
        {
            if (nums[i] < target)
            {
                begin = i + 1;
            }
            else
            {
                end = i - 1;
            }

            i = begin + (end - begin) / 2;
        }

        return i;
    }
};
