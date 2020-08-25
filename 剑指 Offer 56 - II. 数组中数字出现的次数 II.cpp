//��ָ Offer 56 - II. ���������ֳ��ֵĴ��� II 
//����
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i + 1 < nums.size())
        {
            if (nums[i] != nums[i + 1])
                return nums[i];
            else
                i += 3;
        }

        return nums[i];
    }
}; 

//λ��ͳ��
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums[0];
        vector<int> bitCount(31, 0);    //������ֻ��Ҫͳ��31λ����
        for (int n : nums)
        {
            for (int i = 0; i < 31; ++i)
                bitCount[i] += (n & (1 << i)) > 0;
        }
        for (int& n : bitCount)
            n %= 3;
        int res = 0, weight = 1;
        for (int i = 0; i < 31; ++i)
        {
            res += weight * bitCount[i];
            if (i == 30)
                break;
            weight *= 2;
        }

        return res;
    }
}; 

//����������Ű�
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[31] = {0};
        for (int data : nums)
        {
            for (int i = 0; i < 31; ++i)
            {
                if (data & (1 << i))
                    ++bits[i];
            }
        }
        int ret = 0;
        for (int i = 0; i < 31; ++i)
            ret |= (bits[i] % 3) << i;

        return ret;
    }
};

 
