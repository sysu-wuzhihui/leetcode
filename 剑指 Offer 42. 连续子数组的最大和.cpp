//剑指 Offer 42. 连续子数组的最大和
//动态规划 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        count[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            count[i] = count[i - 1] > 0 ? count[i - 1] + nums[i] : nums[i];
            res = count[i] > res ? count[i] : res;
        }

        return res;
    }
}; 

//优化空间复杂度，当前状态只取决于上一个状态，只需要一个变量保存上一个状态即可
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last = nums[0];
        int ret = last;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (last > 0)
                last += nums[i];
            else
                last = nums[i];
            ret = max(ret, last);
        }

        return ret;
    }
}; 
