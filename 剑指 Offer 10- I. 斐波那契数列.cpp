//剑指 Offer 10- I. 斐波那契数列
//1递归，但是重复调用函数，复杂度o(2^n)
//2记忆化递归，用一个数组记录中间结果，空间复杂度o(n)
//3动态规划，由于只需要前面两个值就可以得到后面的值，所以空间复杂度o(1)

//动态规划 
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int a = 0, b = 1;
        int  res;
        while (n-- >= 2)
        {
            res = (a + b) % 1000000007;
            a = b;
            b = res;
        }

        return res;
    }
}; 
