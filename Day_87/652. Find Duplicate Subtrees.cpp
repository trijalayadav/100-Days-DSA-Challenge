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
// class Solution {
// public:
//     bool isSame(TreeNode* a, TreeNode* b) {
//         if (!a && !b)
//             return true;
//         if (!a || !b)
//             return false;
//         return a->val == b->val && isSame(a->left, b->left) &&
//                isSame(a->right, b->right);
//     }
//     void collect(TreeNode* root, vector<TreeNode*>& subs) {
//         if (!root)
//             return;
//         subs.push_back(root);
//         collect(root->left, subs);
//         collect(root->right, subs);
//     }
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         // brute
//         //  vector<TreeNode*> subs, res;
//         //  collect(root, subs);

//         // int n = subs.size();
//         // vector<bool> visited(n, false);

//         // for (int i = 0; i < n; i++) {
//         //     if (visited[i])
//         //         continue;
//         //     bool found = false;
//         //     for (int j = i + 1; j < n; j++) {
//         //         if (visited[j])
//         //             continue;
//         //         if (isSame(subs[i], subs[j])) {
//         //             visited[j] = true;
//         //             if (!found) {
//         //                 res.push_back(subs[i]);
//         //                 found = true;
//         //             }
//         //         }
//         //     }
//         //     if (found)
//         //         visited[i] = true;
//         // }
//         // return res;
//     }
// };

// better
// class Solution {
// public:
//     unordered_map<string, int> freq;
//     vector<TreeNode*> res;

//     string serialize(TreeNode* root) {
//         if (!root)
//             return "#";
//         string s = to_string(root->val) + "," + serialize(root->left) + "," +
//                    serialize(root->right);
//         if (++freq[s] == 2)
//             res.push_back(root);
//         return s;
//     }

//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         serialize(root);
//         return res;
//     }
// };

// optimal
class Solution
{
public:
    unordered_map<string, int> subtreeId; // map serialization -> ID
    unordered_map<int, int> count;        // map ID -> frequency
    vector<TreeNode *> res;
    int uid = 1; // unique ID counter

    int getId(TreeNode *root)
    {
        if (!root)
            return 0; // null -> ID 0
        string key = to_string(root->val) + "," + to_string(getId(root->left)) +
                     "," + to_string(getId(root->right));

        if (!subtreeId.count(key))
        {
            subtreeId[key] = uid++;
        }
        int id = subtreeId[key];
        if (++count[id] == 2)
            res.push_back(root);
        return id;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        getId(root);
        return res;
    }
};