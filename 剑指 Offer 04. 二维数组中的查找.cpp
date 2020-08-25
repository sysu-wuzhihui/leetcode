//剑指 Offer 04. 二维数组中的查找
//1.暴力发，逐一搜索，复杂度o(n*M) 
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0 ; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }

        return false;
    }
};

//2.从右上角开始，类似二叉树的查找,复杂度o(n+m) 
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return false;
        int m = matrix[0].size();
        if (m == 0)
            return false;
        for (int i = 0, j = m - 1; i < n && j >= 0;)
        {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                --j;
            else
                ++i;
        }

        return false;
    }
};
