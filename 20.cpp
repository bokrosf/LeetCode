// https://leetcode.com/problems/valid-parentheses/

#include <set>
#include <map>
#include <stack>

class Solution 
{
public:
    bool isValid(std::string s) 
    {
        std::set<char> opening_brackets = { '(', '[', '{' };
        std::map<char, char> closing_brackets = { { ')', '('}, {']', '['}, {'}', '{'} };
        std::stack<char> openings;
        
        for (const char bracket : s)
        {
            if (opening_brackets.contains(bracket))
            {
                openings.push(bracket);
            }
            else if (openings.empty() || openings.top() != closing_brackets[bracket])
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
