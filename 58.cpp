// https://leetcode.com/problems/length-of-last-word/

class Solution
{
public:
    int lengthOfLastWord(const string &s)
    {
        auto it = s.crbegin();
        const char separator = ' ';

        while (*it == separator)
        {
            ++it;
        }

        int word_length = 0;

        while (it != s.crend() && *it != separator)
        {
            ++word_length;
            ++it;
        }

        return word_length;
    }
};
