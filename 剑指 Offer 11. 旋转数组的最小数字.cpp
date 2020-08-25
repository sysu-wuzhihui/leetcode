//剑指 Offer 11. 旋转数组的最小数字
//二分查找。二分查找三要素：循环条件，判断条件，边界收缩 
//问题的本质，在两个排序数组中找右排序数组的起始值，其中右排序数组小于等于左排序数组
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        if (len < 2)
            return numbers[0];
        int left = 0, right = len - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[right])	//mid在左排序数组 
                left = mid + 1;
            else if (numbers[mid] < numbers[right])	//mid在右排序数组 
                right = mid;
            else	//无法确定，安全操作--j 
                --right;
        }

        return numbers[left];
    }
};
