//剑指 Offer 53 - II. 0～n-1中缺失的数字
//有序数组，考虑二分查找。此题缺失数字之后的部分，nums[index]>index,前面则有nums[index]==index 

//o(n)线性搜索 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            if (i != nums[i])
                return i;

        return nums.size();
    }
};

 
//二分查找 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right)	//跳出循环时，left指向左边部分右边的下一个位置，即缺失的数，right指向左边部分最后一个数 
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > mid)    //也可以nusm[mid] != mid
                right = mid - 1;
            else    //nums[mid] == mid, 不可能存在nums[mid] < mid
                left = mid + 1; 
        }

        return left;
    }
};

//二分查找，找左边部分的右边界
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = -1, r = nums.size() - 1;	//左边部分可能不存在，所以l初始为-1 
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;	//注意这里mid向右靠 
            if (mid == nums[mid])
                l = mid;
            else
                r = mid - 1;
        }

        return l + 1;
    }
};

//二分查找，找右边部分的左边界
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size();	//右边部分可能不存在，所以r初始为nums.size() 
        while (l < r)
        {
            int mid = l + (r - l) / 2;	//注意这里向左靠 
            if (mid == nums[mid])
                l = mid + 1;
            else
                r = mid;
        }

        return l;	//注意这里返回不是l-1 
    }
};
 
