//剑指 Offer 19. 正则表达式匹配
//动态规划算法，关键是分析出状态转移方程
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = false;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = p[j - 1] == '*' ? dp[0][j - 2] : false;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == '.' || s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                        dp[i][j] = (dp[i - 1][j] || dp[i][j - 2]);
                    else
                        dp[i][j] = dp[i][j - 2];
                }
                else
                    dp[i][j] = false;           
            }
        }

        return dp[m][n];
    }
};

//递归算法
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        if (m == 0 && n == 0)
            return true;
        if (m != 0 && n == 0)
            return false;
        if  (m == 0 && n != 0)
        {
            if (p[n - 1] != '*')
                return false;
            if (n > 1)
                return isMatch(s, string(p.begin(), p.end() - 2));
            else
                return false;
        }
        if (p[n - 1] == '.' || p[n - 1] == s[m - 1])
            return isMatch(string(s.begin(), s.end() - 1), string(p.begin(), p.end() - 1));
        else if (p[n - 1] != '*')
                return false;
        else
        {
            bool res = false;
            if (n > 1)
                res = isMatch(s, string(p.begin(), p.end() - 2));
            if (n > 1 && (p[n - 2] == '.' || p[n - 2] == s[m - 1]))
                res = res || isMatch(string(s.begin(), s.end() - 1), string(p.begin(), p.end()));
            return res;
        }

    }

}; 
