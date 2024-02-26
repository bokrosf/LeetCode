// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution 
{
public:
    int removeDuplicates(std::vector<int> &nums) 
    {
        int unique_element = nums[0];
        int unique_count = 1;

        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != unique_element)
            {
                unique_element = nums[i];
                nums[unique_count++] = unique_element;
            }
        }

        return unique_count;
    }
};
