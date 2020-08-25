//剑指 Offer 66. 构建乘积数组
//对称相乘，两次遍历
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty())
            return {};
        vector<int> res(a.size(), 1);
        int left = 1, right = 1;
        for (int i = 0; i < a.size(); ++i)
        {
            res[i] *= left;
            left *= a[i];
        }
        for (int j = a.size() - 1; j >= 0; --j)
        {
            res[j] *= right;
            right *= a[j];
        }

        return res;
    }
}; 

//一次遍历即可
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty())
            return {};
        vector<int> res(a.size(), 1);
        int left = 1, right = 1;
        for (int i = 0; i < a.size(); ++i)
        {
            res[i] *= left;
            left *= a[i];
            res[a.size() - 1 - i] *= right;
            right *= a[a.size() - 1 - i];
        }

        return res;
    }
}; 
