#include <utility>
#include <queue>

// Definition for a binary tree node.
// struct TreeNode 
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

typedef std::pair<TreeNode *, TreeNode *> node_pair;

class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        std::queue<node_pair> nodes;
        nodes.push(std::make_pair(p, q));

        while (!nodes.empty())
        {
            node_pair checked = nodes.front();
            nodes.pop();
            bool same_nullability = (checked.first != nullptr) == (checked.second != nullptr);

            if (!same_nullability)
            {
                return false;
            }

            if (checked.first)
            {
                if (checked.first->val != checked.second->val)
                {
                    return false;
                }

                nodes.push(std::make_pair(checked.first->left, checked.second->left));
                nodes.push(std::make_pair(checked.first->right, checked.second->right));
            }
        }

        return true;
    }
};
