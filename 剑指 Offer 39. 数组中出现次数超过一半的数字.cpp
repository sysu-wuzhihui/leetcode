//剑指 Offer 39. 数组中出现次数超过一半的数字
//正负抵消法，最优解法 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (count == 0)
                res = nums[i];
            count += nums[i] == res ? 1 : -1;
        }

        return res;
    }
}; 

//排序，返回中间的数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
}; 
