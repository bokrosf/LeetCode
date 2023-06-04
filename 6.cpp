#include <iostream>
#include <string>

// https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    std::string convert(std::string s, int row_count)
    {
        std::string row_texts[row_count];

        for (int i = 0; i < row_count; ++i)
        {
            row_texts[i] = "";
        }

        int row = 0;
        int row_offset = row_count > 1 ? 1 : 0;

        for (auto c : s)
        {
            std::cout << "row index = " << row << std::endl;
            row_texts[row] += c;
            
            if (row + row_offset < 0 || row + row_offset == row_count)
            {
                row_offset *= -1;
            }
            
            row += row_offset;
        }

        for (int i = 1; i < row_count; ++i)
        {
            row_texts[0] += std::move(row_texts[i]);
        }

        return row_texts[0];
    }
};
