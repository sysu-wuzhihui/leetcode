//剑指 Offer 29. 顺时针打印矩阵
//控制左上和右下角即可
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        vector<int> ret;
        int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; ++i)
                ret.push_back(matrix[top][i]);
            for (int i = top + 1; i <= bottom; ++i)
                ret.push_back(matrix[i][right]);
            for (int i = right - 1; top != bottom && i >= left; --i)
                ret.push_back(matrix[bottom][i]);
            for (int i = bottom - 1; left != right && i >= top + 1; --i)
                ret.push_back(matrix[i][left]);

            ++top;
            ++left;
            --bottom;
            --right;
        }

        return ret;
    }
}; 

//模拟
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return vector<int>();
        int m = matrix.size(), n = matrix[0].size();
        int total = m * n;
        vector<int> res(total);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        //右下左上 
        int nextRow[4] = {0, 1, 0, -1};
        int nextCol[4] = {1, 0, -1, 0};
        int nextIndex = 0;
        int row = 0, col = 0;
        int count = 0;
        while (count < total)
        {
            visited[row][col] = true;
            res[count++] = matrix[row][col];
            row += nextRow[nextIndex];
            col += nextCol[nextIndex];
            //某个方向到头了，换一个方向 
            if (row >= m || row < 0 || col >= n || col < 0 || visited[row][col])
            {
                row -= nextRow[nextIndex];
                col -= nextCol[nextIndex];
                nextIndex = (nextIndex + 1) % 4;
                row += nextRow[nextIndex];
                col += nextCol[nextIndex];
            }
            
        }

        return res;
    }
}; 
