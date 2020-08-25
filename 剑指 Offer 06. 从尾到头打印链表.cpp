//剑指 Offer 06. 从尾到头打印链表
//可以利用栈的特性，或者递归，也可以使用stl的reverse操作
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //stl的reverse操作 
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

//递归
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
