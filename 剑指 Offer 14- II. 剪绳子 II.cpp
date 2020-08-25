//��ָ Offer 14- II. ������ II
//ע����������������⣬�����Ҫ�����ݹ��������� 

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n - 1;
        int a = n / 3, b = n % 3, p = 1000000007;
        if (b == 0)
            return pow(3, a, p);
        if (b == 1)
            return pow(3, a - 1, p) * 4 % p;
        return pow(3, a, p) * 2 % p;
    }

	//�Զ���pow���������������࣬��ֹ��� 
    long long pow(int a, int b, int p)
    {
        long long res = 1, x = a;   //�м���x��res���ܻ�int���
        while (b)
        {
            if (b & 1)
                res = (res * x) % p;
            x = (x * x) % p;
            b >>= 1;
        }

        return res;
    }
};
