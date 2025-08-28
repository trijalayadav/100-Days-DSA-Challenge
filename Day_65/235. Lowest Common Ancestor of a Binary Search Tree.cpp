/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    // TreeNode* solve(TreeNode* root, int& num1, int& num2) {
    //     if (!root)
    //         return nullptr;
    //     if (num1 < root->val && num2 < root->val) {
    //         return solve(root->left, num1, num2);
    //     } else if(num1 > root->val && num2 > root->val){
    //         return solve(root->right, num1, num2);
    //     }
    //     return root;
    // }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // recursive
        //  int num1 = p->val, num2 = q->val;
        //  if (num1 > num2)
        //      swap(num1, num2);
        //  return solve(root, num1, num2);

        // iterative
        //  while (root) {
        //      if (root->val > p->val && root->val > q->val) {
        //          root = root->left;
        //      }
        //      else if (root->val < p->val && root->val < q->val) {
        //          root = root->right;
        //      }
        //      else {
        //          return root;
        //      }
        //  }
        //  return nullptr;

        // generic binary tree -also works if not bst
        if (!root || root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;
        return left ? left : right;
    }
};