//��ָ Offer 18. ɾ������Ľڵ�
//ʹ�ÿ�ͷ�ڵ㣬ͳһ����ͷ�������ڵ� 
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

//��ʹ�ÿ�ͷ�ڵ�
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
