#include <algorithm>
#include <string>
#include <unordered_map>

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution 
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        size_t max_length = 0;
        size_t start_of_substring = 0;
        std::unordered_map<char, size_t> substring_characters;

        for (size_t i = 0; i < s.length(); ++i)
        {
            const char current_character = s[i];

            if (substring_characters.find(current_character) != substring_characters.end()) 
            {
                if (max_length >= s.length() - (substring_characters[current_character] + 1))
                {
                    return max_length;
                }
                
                for (size_t remove_index = start_of_substring; remove_index < substring_characters[current_character]; ++remove_index)
                {
                    substring_characters.erase(s[remove_index]);
                }
                
                start_of_substring = substring_characters[current_character] + 1;
            }

            substring_characters[current_character] = i;
            max_length = std::max(max_length, substring_characters.size());
        }

        return max_length;
    }
};
