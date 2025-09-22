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

// brute
// class Solution {
// public:
//     vector<int> vals;
//     void collect(TreeNode* root) {
//         if (!root)
//             return;
//         vals.push_back(root->val);
//         collect(root->left);
//         collect(root->right);
//     }
//     int minDiffInBST(TreeNode* root) {
//         collect(root);
//         int n = vals.size();
//         int ans = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 ans = min(ans, abs(vals[i] - vals[j]));
//             }
//         }
//         return ans;
//     }
// };

// better
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& arr) {
//         if (!root)
//             return;
//         inorder(root->left, arr);
//         arr.push_back(root->val);
//         inorder(root->right, arr);
//     }

//     int minDiffInBST(TreeNode* root) {
//         vector<int> arr;
//         inorder(root, arr);
//         int ans = INT_MAX;
//         for (int i = 1; i < arr.size(); i++) {
//             ans = min(ans, abs(arr[i] - arr[i - 1]));
//         }
//         return ans;
//     }
// };

// optimal
// class Solution {
// public:
//     void inorder(TreeNode* node, int& prev, int& ans) {
//         if (!node)
//             return;
//         inorder(node->left, prev, ans);
//         if (prev != -1)
//             ans = min(ans, node->val - prev);
//         prev = node->val;
//         inorder(node->right, prev, ans);
//     }
//     int minDiffInBST(TreeNode* root) {
//         int ans = INT_MAX;
//         int prev = -1;
//         inorder(root, prev, ans);
//         return ans;
//     }
// };

// morris traversal
class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        TreeNode *curr = root;
        TreeNode *pre = nullptr;
        int prev = -1, ans = INT_MAX;

        while (curr)
        {
            if (!curr->left)
            {
                if (prev != -1)
                    ans = min(ans, curr->val - prev);
                prev = curr->val;
                curr = curr->right;
            }
            else
            {
                pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;
                if (!pre->right)
                {
                    pre->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pre->right = nullptr;
                    if (prev != -1)
                        ans = min(ans, curr->val - prev);
                    prev = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
