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
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> arr;
//         ListNode* temp = head;
//         while (temp != NULL) {
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         int i = 0, j = arr.size() - 1;
//         while (i < j) {
//             if (arr[i] != arr[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
// };
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        // Find middle (slow will point to middle)
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Compare first and second half
        ListNode *left = head;
        ListNode *right = prev;
        while (right)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
