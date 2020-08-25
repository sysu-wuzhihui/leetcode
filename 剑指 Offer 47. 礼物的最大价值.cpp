//剑指 Offer 47. 礼物的最大价值
//递归，会超时
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return helper(m - 1, n - 1, grid);
    }

    int helper(int i, int j, vector<vector<int>>& grid)
    {
        if (i < 0 || j < 0)
            return 0;
        return max(helper(i - 1, j, grid), helper(i, j - 1, grid)) + grid[i][j];
    }
};

//带备忘录递归，保存中间结果，避免重复调用计算中间结果的函数
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> save(m, vector<int>(n, 0));
        return helper(m - 1, n - 1, grid, save);
    }

    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& save)
    {
        if (i < 0 || j < 0)
            return 0;
        if (save[i][j] > 0)
            return save[i][j];
        return save[i][j] =  max(helper(i - 1, j, grid, save), helper(i, j - 1, grid, save)) + grid[i][j];
    }
}; 
 
//动态规划
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[i][j] = grid[i][j];
                if (i - 1 >= 0 && j - 1 >= 0)
                    dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
                else if (i - 1 >= 0)
                    dp[i][j] += dp[i - 1][j];
                else if (j - 1 >= 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

//优化时间，把第一行第一列的判断拿出大循环
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                
                dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];

            }
        }

        return dp[m][n];
    }
}; 

//优化空间，直接在原矩阵上操作。 
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; ++i)
            grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; ++j)
            grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);

            }
        }

        return grid[m - 1][n - 1];
    }
}; 

 
