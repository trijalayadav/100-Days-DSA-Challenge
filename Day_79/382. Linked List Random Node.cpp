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
//     // vector<int> arr;
//     ListNode* head;
//     int n = 0;

// public:
//     Solution(ListNode* head) {
//         // ListNode* temp = head;
//         // while (temp) {
//         //     arr.push_back(temp->val);
//         //     n++;
//         //     temp = temp->next;
//         // }
//         this->head = head;
//         ListNode* temp = head;
//         while (temp) {
//             n++;
//             temp = temp->next;
//         }
//     }

//     int getRandom() {
//         int idx = rand() % n;
//         // return arr[idx];
//         ListNode* temp = head;
//         while (idx--) {
//             temp = temp->next;
//         }
//         return temp->val;
//     }
// };

// optimal-reservoir sampling
class Solution
{
    ListNode *head;

public:
    Solution(ListNode *head)
    {
        this->head = head;
    }

    int getRandom()
    {
        int result = -1;
        int count = 0;
        ListNode *temp = head;

        while (temp)
        {
            count++;
            if (rand() % count == 0)
            {
                result = temp->val;
            }
            temp = temp->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */