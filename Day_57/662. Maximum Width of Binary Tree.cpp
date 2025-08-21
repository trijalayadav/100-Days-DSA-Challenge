/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        long long res = 0;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            res = max(res, (long long)(right - left + 1));

            for (int i = 0; i < size; i++)
            {
                auto [node, idx] = q.front();
                q.pop();

                unsigned long long normalized = idx - left;

                if (node->left)
                    q.push({node->left, 2 * normalized + 1});
                if (node->right)
                    q.push({node->right, 2 * normalized + 2});
            }
        }
        return (int)res;
    }
};
