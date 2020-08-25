//剑指 Offer 62. 圆圈中最后剩下的数字
//找规律。f(n,m)=y,表示剩下下标为y（从0开始数），f(n-1,m)=x, 表示剩下下标为x（(m-1)%n被删除，从m%n开始数）
//所以有y=(m%n+x)%n=(m+x)%n 
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1)
            return 0;
        return (m + lastRemaining(n- 1, m)) % n;
    }
};

//迭代
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ret = 0;
        for (int i = 2; i <= n; ++i)
            ret = (m + ret) % i;
        return ret;
    }
};
