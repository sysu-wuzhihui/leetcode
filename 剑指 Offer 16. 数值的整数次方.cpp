//剑指 Offer 16. 数值的整数次方
//逐次相乘，复杂度o(n),快速幂算法o(logn)
//快速幂.两种理解方式:1.指数二进制展开 2.二分法递推 
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
        //二进制展开或者二分法都能解释下面的过程。二进制展开解释更直观。 
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

//递归实现
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

	//二分法解释下面的过程 
    double helper(double x, long long m)
    {
        if (m == 1)
            return x;
        if (m & 1)
            return helper(x * x, m >> 1) * x;
        return helper(x * x, m >> 1);
    }
}; 
