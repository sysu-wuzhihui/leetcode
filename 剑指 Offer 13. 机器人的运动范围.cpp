//剑指 Offer 13. 机器人的运动范围
//典型的搜索问题，dfs或者bfs都可以解决
//dfs 
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (k == 0)
            return 1;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(m, n, 0, 0, k, visited);
    }

    int dfs(int& m, int& n, int i, int j, int& k, vector<vector<bool>>& visited)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || digitSum(i) + digitSum(j) > k)
            return 0;
        visited[i][j] = true;
        int res = 1;
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        for (int index = 0; index < 4; ++index)
            res += dfs(m, n, i + x[index], j + y[index], k, visited);
        return res;
    }

    int digitSum(int n)
    {
        int res = 0;
        while (n)
        {
            res += n % 10;
            n /= 10;
        }

        return res;
    }
};

//dfs优化，只需要向右和向下搜索即可找出连通区域
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (k == 0)
            return 1;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(m, n, 0, 0, k, visited);
    }

    int dfs(int& m, int& n, int i, int j, int& k, vector<vector<bool>>& visited)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || digitSum(i) + digitSum(j) > k)
            return 0;
        visited[i][j] = true;
        int res = 1;
        int x[2] = {1, 0};
        int y[2] = {0, 1};
        for (int index = 0; index < 2; ++index)
            res += dfs(m, n, i + x[index], j + y[index], k, visited);
        return res;
    }

    int digitSum(int n)
    {
        int res = 0;
        while (n)
        {
            res += n % 10;
            n /= 10;
        }

        return res;
    }
};

//bfs
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (k == 0)
            return 1;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        int res = 0;
        while (!q.empty())
        {
            pair<int, int> tmp = q.front();
            q.pop();
            ++res;
            int x = tmp.first, y = tmp.second;
            
            if (x + 1 < m && !visited[x + 1][y] && digitSum(x + 1) + digitSum(y) <= k)
            {
                visited[x + 1][y] = true;
                q.push({x + 1, y});
            }
            if (y + 1 < n && !visited[x][y + 1] && digitSum(x) + digitSum(y + 1) <= k)
            {
                visited[x][y + 1] = true;
                q.push({x, y + 1});
            }
        }

        return res;
    }

    int digitSum(int n)
    {
        int res = 0;
        while (n)
        {
            res += n % 10;
            n /= 10;
        }

        return res;
    }
}; 
