//剑指 Offer 52. 两个链表的第一个公共节点
//1.暴力搜索，o(nm)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode *curA = headA, *curB = headB;
        while (curA)
        {
            curB = headB;
            while (curB)
            {
                if (curB == curA)
                    return curA;
                curB = curB->next;
            }
            curA = curA->next;
        }

        return NULL;
    }
}; 

//2.双指针，设三段长度为a，b，c(共有段）,使两个指针都走a+b+c步，则相遇在公共节点处
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode *curA = headA, *curB = headB;
        while (curA != curB)    //若没有重叠部分，两者也会同时走到NULL，依然可以跳出循环
        {
            if (!curA)
                curA = headB;
            else
                curA = curA->next;
            if (!curB)
                curB = headA;
            else
                curB = curB->next;        
        }

        return curA;
    }
}; 
