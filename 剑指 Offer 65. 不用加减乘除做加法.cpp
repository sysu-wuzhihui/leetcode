//��ָ Offer 65. ���üӼ��˳����ӷ�
class Solution {
public:
    int add(int a, int b) {
        if (b == 0)
            return a;
        
        return add(a ^ b, (a & b & ~(1 << 31)) << 1);   //�������Ʊ����ֶ�ȥ�����λ��1.����ת��Ϊ�޷�����(unsigned int)(a & b) << 1 
    }
};

//����
class Solution {
public:
    int add(int a, int b) {
        unsigned int ret = a, step = b;
        while (step)
        {
            int tmp = ret;
            ret ^= step;
            step = (step & tmp) << 1;
        }

        return ret;
    }
};
