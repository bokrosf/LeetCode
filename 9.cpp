#include <iostream>
#include <limits>

// https://leetcode.com/problems/palindrome-number/

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
		{
			return false;
		}

		int max_last_digit = std::numeric_limits<int>::max() % 10;
		int last_accumulated = std::numeric_limits<int>::max() / 10;
		int original = x;
		int reversed = 0;

		while (x > 0)
		{
			int digit = x % 10;

			if (reversed > last_accumulated || (reversed == last_accumulated && digit > max_last_digit))
			{
				return false;
			}

			reversed *= 10;
			reversed += digit;
			x /= 10;
		}
		
		return reversed == original;
	}
};

int main()
{
	std::cout << "palindrome number" << std::endl;
	Solution solution;
	std::cout << solution.isPalindrome(10201) << std::endl;

	return 0;
}
