/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void traverse(TreeNode *root, vector<int> &res)
    {
        res.push_back(root->val);
        if (root->left)
        {
            traverse(root->left, res);
        }
        if (root->right)
        {
            traverse(root->right, res);
        }
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }
        if (root->left == NULL && root->right == NULL)
        {
            res.push_back(root->val);
            return res;
        }
        traverse(root, res);
        return res;
    }
};