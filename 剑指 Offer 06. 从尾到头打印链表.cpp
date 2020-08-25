//��ָ Offer 06. ��β��ͷ��ӡ����
//��������ջ�����ԣ����ߵݹ飬Ҳ����ʹ��stl��reverse����
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //stl��reverse���� 
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

//�ݹ�
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
    vector<int> reversePrint(ListNode* head) {
        if (!head)
            return {};
        vector<int> res = reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};
