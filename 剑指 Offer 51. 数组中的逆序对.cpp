//��ָ Offer 51. �����е������
//���ù鲢���򡣹鲢����������ǻ�����ֲ���������У��ںϲ���ʱ�����ͳ������� 
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
			if (nums[i] <= nums[j])	//ע�ⲻ���� nums[i] < nums[j]
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

//������������ʵ��
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        vector<int> tmp(nums.size());   //������һ���������飬���ô��ݣ���ֹ�ݹ�ʱ���ϴ�����������ʱ���飬leetcodeʵ����Խ�Լһ���ʱ�������֮�����ڴ� 
        
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
