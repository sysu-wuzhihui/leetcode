//剑指 Offer 22. 链表中倒数第k个节点
//快慢指针
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head)
            return head;
        ListNode *fast = head, *slow = head;
        while (k--)
            fast = fast->next;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
}; 
