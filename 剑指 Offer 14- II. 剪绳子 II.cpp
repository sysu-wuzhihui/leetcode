//剑指 Offer 14- II. 剪绳子 II
//注意求幂整数溢出问题，因此需要在求幂过程中求余 

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

	//自定义pow函数，快速幂求余，防止溢出 
    long long pow(int a, int b, int p)
    {
        long long res = 1, x = a;   //中间结果x和res可能会int溢出
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
