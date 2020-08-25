//��ָ Offer 39. �����г��ִ�������һ�������
//���������������Žⷨ 
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

//���򣬷����м����
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
}; 
