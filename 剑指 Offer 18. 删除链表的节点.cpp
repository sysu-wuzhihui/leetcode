//剑指 Offer 18. 删除链表的节点
//使用空头节点，统一处理头和其它节点 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head, *pre = dummy;
        while (cur && cur->val != val)
        {
            pre = cur;
            cur = cur->next; 
        }
        if (cur)
            pre->next = cur->next;
            
        return dummy->next;
    }
};

//不使用空头节点
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head)
            return head;
        ListNode* cur = head, *pre = NULL;
        if (head->val == val)
            return head->next;
        while (cur)
        {
            if (cur->val == val)
            {
                pre->next = cur->next;
                break;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
}; 
