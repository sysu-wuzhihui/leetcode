//��ָ Offer 16. ��ֵ�������η�
//�����ˣ����Ӷ�o(n),�������㷨o(logn)
//������.������ⷽʽ:1.ָ��������չ�� 2.���ַ����� 
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        int flag = 0;
        long long nn = n;
        if (nn < 0)
        {
            x = 1 / x;
            nn = -nn;
        }
        double res = 1;
        //������չ�����߶��ַ����ܽ�������Ĺ��̡�������չ�����͸�ֱ�ۡ� 
        while (nn > 0)
        {
            if (nn & 0x1)
                res *= x;
            x = x * x;
            nn >>= 1;
        }

        return res;
    }
}; 

//�ݹ�ʵ��
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (x == 0)
            return 0;
        long long m = n;
        if (n < 0)
        {
            x = 1 / x;
            m = -m;
        }

        return helper(x, m);
    }

	//���ַ���������Ĺ��� 
    double helper(double x, long long m)
    {
        if (m == 1)
            return x;
        if (m & 1)
            return helper(x * x, m >> 1) * x;
        return helper(x * x, m >> 1);
    }
}; 
