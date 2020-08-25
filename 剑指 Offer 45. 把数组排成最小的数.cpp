//剑指 Offer 45. 把数组排成最小的数
//自定义一个排序比较函数即可
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){ return to_string(a) + to_string(b) < to_string(b) + to_string(a); });
        stringstream ss;
        for (int data : nums)
            ss << data;
        return ss.str();
    }
};
