// https://leetcode.com/problems/plus-one/description/

#include <algorithm>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        std::vector<int> result;
        int carried = 1;

        for (auto it = digits.crbegin(); it != digits.crend(); ++it)
        {
            int added = *it + carried;
            carried = added > 9;
            result.push_back(added % 10);
        }

        if (carried)
        {
            result.push_back(carried);
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};
