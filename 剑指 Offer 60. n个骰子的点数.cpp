//��ָ Offer 60. n�����ӵĵ���
//��̬�滮��dp[i][j]��ʾi�����ӣ�������Ϊj�Ĵ���
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
        for (int i = 1; i <= 6; ++i)
            dp[1][i] = 1;
        vector<double> res(5 * n + 1);
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i; j <= 6 * i; ++j)
            {
                for (int k = 1; k <= 6 && j - k >= i - 1; ++k)
                    dp[i][j] += dp[i - 1][j - k];
            }

        }
        int total = pow(6, n); 
        for (int i = n; i <= 6 * n; ++i)
            res[i - n] = dp[n][i] / (double)total;

        return res;
    }
}; 

//�ռ��Ż�����ǰ״ֻ̬ȡ������һ��״̬�����ʹ��һά���鱣����һ��״̬����
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<int> dp(6 * n + 1);
        for (int i = 1; i <= 6; ++i)
            dp[i] = 1;
        vector<double> res(5 * n + 1);
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 6 * i; j >= i; --j)    //ע��j����ֵ˳��
            {
                dp[j] = 0;
                for (int k = 1; k <= 6 && j - k >= i - 1; ++k)
                    dp[j] += dp[j - k];
            }
        }
        int total = pow(6, n); 
        for (int i = n; i <= 6 * n; ++i)
            res[i - n] = dp[i] / (double)total;

        return res;
    }
}; 
