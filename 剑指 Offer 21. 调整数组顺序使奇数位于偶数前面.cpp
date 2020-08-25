//��ָ Offer 21. ��������˳��ʹ����λ��ż��ǰ��
//˫ָ��
//1.ǰ�󽻻�
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

//2.����ָ��
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] & 1) //�ȼ���%2 
                swap(nums[slow++], nums[fast]);
            ++fast;
        }

        return nums;
    }
}; 
