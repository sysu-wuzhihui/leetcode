//��ָ Offer 61. �˿����е�˳��
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int small, smallIndex, zero = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != 0)
            {
                small = nums[i];
                smallIndex = i;
                break;
            }
            else
                ++zero;

        for (int val = small, j = smallIndex; val <= small + 4 && j < nums.size(); ++val)
        {
            if (nums[j] != val)
                if (zero > 0)
                    --zero;
                else    
                    return false;
            else
                ++j;
        }

        return true;
    }       
}; 

//1.���ظ���2.���ֵ����СֵС��5 ����������֤��˳��
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int arr[14] = {0};
        int minValue = 13, maxValue = 1;
        for (int i : nums)
            if (i != 0)
                if (arr[i] == 1)
                    return false;
                else
                {
                    minValue = min(minValue, i);
                    maxValue = max(maxValue, i);
                    arr[i] = 1;
                }

        return maxValue - minValue < 5;
        
    }
}; 
