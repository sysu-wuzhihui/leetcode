//��ָ Offer 12. �����е�·��
//dfs���������� 
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

//�������Ƚ�ӷ�ף�������д�����¡�����Ч�ʻ���΢��һ�㣬��Ϊ���������жϺ������������ֱ�ӱ������ڱ����н����ж� 
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
        visited[i][j] = true;	//��Ƿ��� 
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        for (int n = 0; n < 4; ++n)
            if (dfs(board, i + x[n], j + y[n], word, k + 1, visited))
                return true;

        visited[i][j] = false; //ȡ����Ƿ��ʣ����� 
        return false;
    }
};
