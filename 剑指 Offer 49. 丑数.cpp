//剑指 Offer 49. 丑数
//动态规划，每个丑数一定是由前面的丑数乘以2或者3或者5得到，复杂度o(n^2) 
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n + 1, INT_MAX);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                if (dp[j] * 2 > dp[i - 1] && dp[j] * 2 < dp[i])
                    dp[i] = dp[j] * 2;
                if (dp[j] * 3 > dp[i - 1] && dp[j] * 3 < dp[i])
                    dp[i] = dp[j] * 3;
                if (dp[j] * 5 > dp[i - 1] && dp[j] * 5 < dp[i])
                    dp[i] = dp[j] * 5;                    
            }
        }

        return dp[n];
    }
}; 

//上述方法改进，不用每次都遍历前面所有丑数，改用三个指针，复杂度o(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        vector<int> nums(n + 1);
        nums[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <=n; ++i)
        {
            nums[i] = min(2 * nums[p2], min(3 * nums[p3], 5 * nums[p5]));
            if (nums[i] == 2 * nums[p2])
                ++p2;
            if (nums[i] == 3 * nums[p3])
                ++p3;
            if (nums[i] == 5 * nums[p5])
                ++p5;
        }

        return nums[n];
    }
};
