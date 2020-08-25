//剑指 Offer 10- II. 青蛙跳台阶问题
//最后一次跳两步或者一步，因此有递推关系f(n)=f(n-1)+f(n-2)，转化为斐波那契问题
class Solution {
public:
    int numWays(int n) {
        if (n < 2)
            return 1;
        int a = 1, b = 1, res;
        while (n-- >= 2)
        {
            res = (a + b) % 1000000007;
            a = b;
            b = res;
        }

        return res;
    }
};
