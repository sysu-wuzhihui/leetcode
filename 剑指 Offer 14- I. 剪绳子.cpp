//剑指 Offer 14- I. 剪绳子
//多种方法可解。1.简单递归，会重复计算，指数复杂度 2.记忆化递归 3.动态规划 4.数学规律，段长3为最优，尾部除3余数注意处理一下即可
//记忆化递归，自顶向下 
class Solution {
public:
    int cuttingRope(int n) {
        if (n <2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> save(n + 1, 0);
        return helper(n, save);
    }

    int helper(int n, vector<int>& save)
    {
        if (n < 3)
            return 1;
        if (save[n] > 0)
            return save[n];
        int res = 0;
        for (int i = 1; i < n; ++i)
            res = max(res, max(i * (n - i), i * helper(n - i, save)));
        save[n] = res;
        return res;
    }

};
 
//动态规划 ，自底向上。f(n) = max{i * (n - i), f(n - i) * i}, 1<= i <= n - 1 ,i * (n - i)表示切两段，f(n - i) * i 表示切两段以上 
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            int max = 0;
            
            for (int j = 1; j <= i - 1; ++j)
            {
                if (dp[i - j] * j > max)
                    max = dp[i - j] * j;
                if (j * (i - j) > max)
                    max = j * (i - j);
            }
            dp[i] = max;
            //cout << max << " ";
        }

        return dp[n];
    }
}; 

//数学规律，可以建立函数求导精确证明3为最优段长。这里从逻辑上来说明 ：对于段长为1，其对总结果无贡献，排除。
//对于段长2，对结果贡献为2倍，对于段长3，对结果贡献为3倍，对于段长4，其对结果贡献为4，但是4可以切成2 2 ，对结果贡献也是4，因此可以用2替代
//对于段长5，对结果贡献为5倍，但是切成2 3后，贡献为6倍，因此可以用2和3来替代，同理更大的段长都不如用2 3来替代所取得的结果大。下面比较2 和 3哪个最优
//取两者最小公倍数6，切为2的段长结果为8，切为3结果为9，因此段长3更优，即3为最优段长。
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n - 1;
        int a = n / 3, b = n % 3;
        if (b == 0)
            return pow(3, a);
        if (b == 1)
            return pow(3, a - 1) * 2 * 2;
        if (b == 2)
            return pow(3, a) * 2;
        return -1;
    }
}; 
 
