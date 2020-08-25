//��ָ Offer 52. ��������ĵ�һ�������ڵ�
//1.����������o(nm)
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

//2.˫ָ�룬�����γ���Ϊa��b��c(���жΣ�,ʹ����ָ�붼��a+b+c�����������ڹ����ڵ㴦
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode *curA = headA, *curB = headB;
        while (curA != curB)    //��û���ص����֣�����Ҳ��ͬʱ�ߵ�NULL����Ȼ��������ѭ��
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
