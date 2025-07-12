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
    int count = 0;
    int result = -1;

    void inOrder(TreeNode *root, int k)
    {
        if (!root || count >= k)
            return;

        inOrder(root->left, k);

        count++;
        if (count == k)
        {
            result = root->val;
            return;
        }

        inOrder(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        inOrder(root, k);
        return result;
    }
};