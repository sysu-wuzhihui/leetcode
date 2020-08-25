//��ָ Offer 42. ���������������
//��̬�滮 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        count[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            count[i] = count[i - 1] > 0 ? count[i - 1] + nums[i] : nums[i];
            res = count[i] > res ? count[i] : res;
        }

        return res;
    }
}; 

//�Ż��ռ临�Ӷȣ���ǰ״ֻ̬ȡ������һ��״̬��ֻ��Ҫһ������������һ��״̬����
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last = nums[0];
        int ret = last;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (last > 0)
                last += nums[i];
            else
                last = nums[i];
            ret = max(ret, last);
        }

        return ret;
    }
}; 
