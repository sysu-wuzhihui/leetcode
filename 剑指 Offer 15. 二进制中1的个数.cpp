//��ָ Offer 15. ��������1�ĸ���
//����λ����
//��λ�ж� 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0)
        {
            res += n & 0x1;
            n = n >> 1;
        }

        return res;
    }
};

//��n&(n-1) 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0)
        {
            res += 1;
            n = n & (n - 1);    //n - 1:���Ҳ��1��0,����֮���0ȫ��1,n&(n-1)�൱�ڰ����Ҳ��1��0,����һ��1����������ͳ��1�ĸ���
        }

        return res;
    }
};

