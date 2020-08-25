//剑指 Offer 51. 数组中的逆序对
//利用归并排序。归并排序的特性是会产生局部有序的序列，在合并的时候进行统计逆序对 
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        vector<int> tmp(nums.size());
        return mergeSort(nums, 0, nums.size() - 1, tmp);
    }

	int mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp)
	{
		if (left >= right)
			return 0;
		int mid = left + (right - left) / 2;
		int count = 0;
		count += mergeSort(nums, left, mid);
		count += mergeSort(nums, mid + 1, right);
		//vector<int> tmp(right - left + 1);
		int pos = 0, i = left, j = mid + 1;
		while (i <= mid && j <= right)
		{
			if (nums[i] <= nums[j])	//注意不能是 nums[i] < nums[j]
			{
				tmp[pos++] = nums[i++];
				count += j - (mid + 1);
			}
			else
				tmp[pos++] = nums[j++];
		}
	
		while (i <= mid)
		{
			tmp[pos++] = nums[i++];
			count += j - (mid + 1);
		}
		while (j <= right)
			tmp[pos++] = nums[j++];
		for (int i = left; i <= right; ++i)
			nums[i] = tmp[i - left];
			
		return count;
	}
}; 

//上述代码优雅实现
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        vector<int> tmp(nums.size());   //先声明一个辅助数组，引用传递，防止递归时不断创建和销毁临时数组，leetcode实测可以节约一半的时间和三分之二的内存 
        
        return mergeSort(nums, 0, nums.size() - 1, tmp);    
    }

	int mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp)
	{
		if (left >= right)
			return 0;
		int mid = left + (right - left) / 2;
			
		return mergeSort(nums, left, mid, tmp) + mergeSort(nums, mid + 1, right, tmp) + mergeCount(nums, left, mid, right, tmp);
	}
	
	int mergeCount(vector<int>& nums, int left, int mid, int right, vector<int>& tmp)
	{
	    int pos = left, i = left, j = mid + 1, count = 0;
	
		while (i <= mid && j <= right)
		{
			if (nums[i] <= nums[j])
			{
				tmp[pos++] = nums[i++];
				count += j - (mid + 1);
			}
			else
				tmp[pos++] = nums[j++];
		}
	
		while (i <= mid)
		{
			tmp[pos++] = nums[i++];
			count += j - (mid + 1);
		}
	
		while (j <= right)
			tmp[pos++] = nums[j++];
	
		for (int i = left; i <= right; ++i)
			nums[i] = tmp[i];
			
		return count;
	}
}; 
