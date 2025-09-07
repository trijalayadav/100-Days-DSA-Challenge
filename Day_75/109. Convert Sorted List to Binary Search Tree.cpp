/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
//     ListNode* findMiddle(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast && fast->next) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         if (prev) {
//             prev->next = nullptr; // cut left half from mid
//         }
//         return slow; // middle node
//     }
//     TreeNode* sortedListToBST(ListNode* head) {
//         if (!head)
//             return nullptr;
//         if (!head->next)
//             return new TreeNode(head->val);

//         ListNode* mid = findMiddle(head);
//         TreeNode* root = new TreeNode(mid->val);

//         root->left = sortedListToBST(head);
//         root->right = sortedListToBST(mid->next);

//         return root;
//     }
// };

class Solution
{
public:
    ListNode *current;

    int getLength(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    TreeNode *buildBST(int n)
    {
        if (n <= 0)
            return nullptr;
        TreeNode *left = buildBST(n / 2);
        TreeNode *root = new TreeNode(current->val);
        root->left = left;
        current = current->next;
        root->right = buildBST(n - n / 2 - 1);

        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        int n = getLength(head);
        current = head;
        return buildBST(n);
    }
};
