// https://leetcode.com/problems/valid-parentheses/

class Solution 
{
private:
    bool isOpening(char bracket)
    {
        switch (bracket)
        {
            case '(':
            case '[':
            case '{':
                return true;
            default:
                return false;
        }
    }

    char opening(char closing)
    {
        switch (closing)
        {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
            default:
                return 0;
        }
    }

public:
    bool isValid(std::string s) 
    {
        std::stack<char> openings;
        
        for (const char bracket : s)
        {
            if (isOpening(bracket))
            {
                openings.push(bracket);
            }
            else if (openings.empty() || openings.top() != opening(bracket))
            {
                return false;
            }
            else
            {
                openings.pop();
            }
        }

        return openings.empty();
    }
};
