//剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
//双指针
//1.前后交换
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            while (i < j && nums[i] % 2 == 1)
                ++i;
            while (i < j && nums[j] % 2 == 0)
                --j;
            swap(nums[i], nums[j]);
        }

        return nums;
    }
};

//2.快慢指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] & 1) //等价于%2 
                swap(nums[slow++], nums[fast]);
            ++fast;
        }

        return nums;
    }
}; 
