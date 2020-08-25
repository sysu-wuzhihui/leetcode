//剑指 Offer 12. 矩阵中的路径
//dfs搜索，回溯 
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visted(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    //visted[i][j] = true;
                    if (dfs(board, word, visted, i, j, 1))
                        return true;
                    //visted[i][j] = false;
                }
                                 
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visted, int i, int j, int k)
    {
        if (k == word.size())
            return true;
        visted[i][j] = true;
        if (i > 0 && !visted[i - 1][j] && word[k] == board[i - 1][j])
        {
            if (dfs(board, word, visted, i - 1, j, k + 1))
                return true;
        }
        if (j > 0 && !visted[i][j - 1] && word[k] == board[i][j - 1])
        {
            if (dfs(board, word, visted, i, j - 1, k + 1))
                return true;
        }
        if (i < board.size() - 1 && !visted[i + 1][j] && word[k] == board[i + 1][j])
        {
            if (dfs(board, word, visted, i + 1, j, k + 1))
                return true;
        }
        if (j < board[0].size() - 1 && !visted[i][j + 1] && word[k] == board[i][j + 1])
        {
            if (dfs(board, word, visted, i, j + 1, k + 1))
                return true;
        }

        visted[i][j] = false;
        return false;
    }
};

//上面代码比较臃肿，更简洁的写法如下。不过效率会稍微差一点，因为上面是先判断后遍历，下面是直接遍历，在遍历中进行判断 
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
                if (dfs(board, i, j, word, 0, visited))
                    return true;
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int k, vector<vector<bool>>& visited)
    {
        if (k == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[k])
            return false;
        visited[i][j] = true;	//标记访问 
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        for (int n = 0; n < 4; ++n)
            if (dfs(board, i + x[n], j + y[n], word, k + 1, visited))
                return true;

        visited[i][j] = false; //取消标记访问，回溯 
        return false;
    }
};
