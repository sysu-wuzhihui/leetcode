//剑指 Offer 17. 打印从1到最大的n位数。如果是大数的话，就需要用到字符串来表示，这个时候该题可以用生成全排列来做，也可以逐一递增字符串来做 
class Solution {
public:
    vector<int> printNumbers(int n) {
        int total = pow(10, n) - 1;
        vector<int> res(total);
        for (int i = 0; i < total; ++i)
            res[i] = i + 1;
        return res;
    }
}; 
