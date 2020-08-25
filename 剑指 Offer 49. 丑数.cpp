//��ָ Offer 49. ����
//��̬�滮��ÿ������һ������ǰ��ĳ�������2����3����5�õ������Ӷ�o(n^2) 
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

//���������Ľ�������ÿ�ζ�����ǰ�����г�������������ָ�룬���Ӷ�o(n)
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
