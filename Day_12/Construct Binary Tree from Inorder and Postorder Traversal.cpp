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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderMap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, inorderMap, postIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &inorderMap,
                    int &postIndex, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode *root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];

        root->right = build(inorder, postorder, inorderMap, postIndex, inIndex + 1, inEnd);
        root->left = build(inorder, postorder, inorderMap, postIndex, inStart, inIndex - 1);

        return root;
    }
};
