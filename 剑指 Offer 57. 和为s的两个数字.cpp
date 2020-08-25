//剑指 Offer 57. 和为s的两个数字
//双指针，从和的值序列某个中间值开始，每次向最接近的更大或者更小的数搜索 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
                return {nums[i], nums[j]};
            else if (nums[i] + nums[j] > target)
                --j;
            else
                ++i;
        }

        return {};
    }
}; 
