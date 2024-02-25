// https://leetcode.com/problems/longest-common-prefix/description/

#include <sstream>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::stringstream prefix;
        bool searching = true;
        int character_index = 0;

        while (searching)
        {
            if (strs[0].size() == character_index)
            {
                return prefix.str();
            }

            char current_character = strs[0][character_index];
            
            for (size_t word_index = 1; searching && word_index < strs.size(); ++word_index)
            {
                searching &= strs[word_index][character_index] == current_character;
            }

            if (searching)
            {
                prefix << current_character;
            }
            
            ++character_index;
        }

        return prefix.str();
    }
};
