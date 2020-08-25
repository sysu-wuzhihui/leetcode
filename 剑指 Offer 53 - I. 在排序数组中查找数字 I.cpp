//剑指 Offer 53 - I. 在排序数组中查找数字 I 
//二分查找分为简单二分，查找左边界，查找右边界等，需要注意细节。循环条件，判断条件，边界更新三个关键点需要注意搭配好 
//一次二分查找，然后线性滑动窗口 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1)
            return 0;
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        if (nums[mid] != target)
            return 0;
        int i = mid, j = mid;
        while (i > 0 && nums[i - 1] == target)
            --i;
        while (j < nums.size() - 1 && nums[j + 1] == target)
            ++j;
        return j - i + 1;
    }
};

//两次二分查找，寻找左右边界
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1)
            return 0;
        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;  //mid偏左
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        int left = r;   //左边界
       
        if (l >= nums.size() || nums[l] != target)  //没有找到则提前返回
            return 0;
        l = 0;
        r = nums.size() - 1;
        while (l < r)
        {
            mid = l + (r - l + 1) / 2;  //mid偏右
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        int right = l;  //右边界。不用再判断target是否存在了，上面找左边界已经判断了

        return right - left + 1;
    }
};
