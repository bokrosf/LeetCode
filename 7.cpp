#include <iostream>
#include <cstdlib>
#include <limits>

// https://leetcode.com/problems/reverse-integer/

class Solution
{
public:
    int reverse(int x)
    {
        int sign = x < 0 ? -1 : 1;
        int last_accumulated = std::numeric_limits<int>::max() / 10;
        int max_last_digit = std::numeric_limits<int>::max() % 10;

        if (sign < 0)
        {
            ++max_last_digit;
        }

        x = std::abs(x);
        int reversed = 0;

        while (x > 0)
        {
            int digit = x % 10;
            
            if (reversed > last_accumulated || (reversed == last_accumulated && digit > max_last_digit))
            {
                return 0;
            }
            
            reversed *= 10;
            reversed += digit;
            x /= 10;
        }

        return sign * reversed;
    }
};

int main()
{
    std::cout << "reverse integer" << std::endl;
    int number = 123;
    Solution solution;
    std::cout << solution.reverse(number) << std::endl;

    return 0;
}
