//剑指 Offer 46. 把数字翻译成字符串

//动态规划
class Solution {
public:
    int translateNum(int num) {
        return helper(to_string(num));
    }

    int helper(string str)
    {
        vector<int> dp(str.size() + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= str.size(); ++i)
        {
          
            if (str[i - 2] == '0' || str[i - 2] > '2' || str[i - 2] == '2' && str[i - 1] > '5')
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 1] + dp[i - 2];
            //cout << dp[i] << endl;
        }

        return dp[str.size()];
    }
};


//动态规划，只使用了前面两个子结果，保留两个变量即可 
class Solution {
public:
    int translateNum(int num) {
        return helper(to_string(num));
    }

    int helper(string str)
    {
        int a = 1, b = 1, res = 1;
        for (int i = 2; i <= str.size(); ++i)
        {
          
            if (str[i - 2] == '0' || str[i - 2] > '2' || str[i - 2] == '2' && str[i - 1] > '5')
                res = b;
            else
                res = a + b;
            
            a = b;
            b = res;
            //cout << dp[i] << endl;
        }

        return res;
    }
}; 

//递归
class Solution {
public:
    int translateNum(int num) {
        if (num < 10)
            return 1;
        if (num % 100 >= 10 && num % 100 <= 25)
            return translateNum(num / 10) + translateNum(num / 100);
        else
            return translateNum(num / 10);
    }

}; 
