//剑指 Offer 57 - II. 和为s的连续正数序列
//直接数学计算，复杂度o(n)
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<int> nums(target / 2 + 2);
        for (int i = 1; i < nums.size(); ++i)
            nums[i] = i;
        vector<vector<int>> ret;
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            int j = helper(i, target);
            if ((i + j) * (j - i + 1) / 2 == target)	//检验j是否满足要求 
                ret.push_back({nums.begin() + i, nums.begin() + j + 1});
        }

        return ret;
    }

    int helper(long long i, int target)	//一元二次方程求解。sqrt理论上是o(n)复杂度，但是硬件设计在一定误差范围内，是常数时间 
    {
        long long a = 1, b = 1, c = i - i * i - 2 * target;
        return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    }
}; 

//滑动窗口 
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target < 3)
            return {};
        vector<vector<int>> res;
        int i = 1, j = 2;
        int count;
        while (i < j)
        {
            count = (i + j) * (j - i + 1) / 2;	//等差数列求和 
                
            if (count == target)
            {
                vector<int> tmp(j - i + 1);
                for (int k = 0; k < tmp.size(); ++k)
                    tmp[k] = i + k;
                res.push_back(tmp);
                i += 2;
                ++j;
            }
            else if (count > target)
                ++i;
            else
                ++j;
        }

        return res;
    }
};

//更好的一种实现，不依赖等差数列求和，适用于任意递增整数数组 
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target < 3)
            return {};
        vector<vector<int>> res;
        int i = 1, j = 2;
        int count = 3;	//窗口和 
        while (i < j && i <= target / 2)
        {
            if (count == target)
            {
                vector<int> tmp(j - i + 1);
                for (int k = 0; k < tmp.size(); ++k)
                    tmp[k] = i + k;
                res.push_back(tmp);
                i += 2;
                ++j;               
                count = count - (i - 2) - (i - 1) + j;
            }
            else if (count > target)
            {
                count -= i;                
                ++i;             
            }
            else
            {
                ++j;
                count += j;
            }
        }

        return res;
    }
}; 
