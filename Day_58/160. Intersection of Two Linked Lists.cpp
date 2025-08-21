/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return NULL;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while (tempA != tempB)
        {
            tempA = (tempA == NULL) ? headA : tempA->next;
            tempB = (tempB == NULL) ? headB : tempB->next;
        }
        return tempA;
    }
};