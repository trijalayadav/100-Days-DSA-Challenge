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
    bool isValid(TreeNode *node, long minVal, long maxVal)
    {
        if (!node)
            return true;

        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return isValid(node->left, minVal, node->val) &&
               isValid(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode *root)
    {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
