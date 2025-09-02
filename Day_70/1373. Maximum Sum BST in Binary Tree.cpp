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
    struct NodeInfo
    {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    int maxSum = 0;

    NodeInfo dfs(TreeNode *root)
    {
        if (!root)
        {
            return {true, 0, INT_MAX, INT_MIN}; // empty tree is BST
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal)
        {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return {true, currSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        return {false, 0, 0, 0}; // not a BST
    }

    int maxSumBST(TreeNode *root)
    {
        dfs(root);
        return maxSum;
    }
};
