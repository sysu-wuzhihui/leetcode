//剑指 Offer 03. 数组中重复的数字 
//1.暴力解法，从前往后便利，两个for循环，复杂度为o(n^2)
//2.hash表法，时间复杂度为o(n)，空间复杂度为o(n) 
//3.考虑数字范围在0-n-1,因此可以就地交换，每个数放到下标等于该数的位置，遇到重复就返回。时间复杂度o(n),空间复杂度为o(1) 

//hash表法 
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> exist(nums.size(), false);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (exist[nums[i]])
                return nums[i];
            exist[nums[i]] = true;
        }

        return -1;
    }
};

//就地交换,每个数放到下标等于该数的位置，遇到重复就返回
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == nums[i])
                continue;
            if (nums[nums[i]] == nums[i])
                return nums[i]; //一定在这里退出程序
            
            swap(nums[i], nums[nums[i]]);
        }

        return -1;  //由题意，不会运行到这里。为了满足编译要求，必须返回值。
    }
}; 
