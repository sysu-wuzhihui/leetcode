//��ָ Offer 03. �������ظ������� 
//1.�����ⷨ����ǰ�������������forѭ�������Ӷ�Ϊo(n^2)
//2.hash����ʱ�临�Ӷ�Ϊo(n)���ռ临�Ӷ�Ϊo(n) 
//3.�������ַ�Χ��0-n-1,��˿��Ծ͵ؽ�����ÿ�����ŵ��±���ڸ�����λ�ã������ظ��ͷ��ء�ʱ�临�Ӷ�o(n),�ռ临�Ӷ�Ϊo(1) 

//hash�� 
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> exist(nums.size(), false);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (exist[nums[i]])
                return nums[i];
            exist[nums[i]] = true;
        }

        return -1;
    }
};

//�͵ؽ���,ÿ�����ŵ��±���ڸ�����λ�ã������ظ��ͷ���
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == nums[i])
                continue;
            if (nums[nums[i]] == nums[i])
                return nums[i]; //һ���������˳�����
            
            swap(nums[i], nums[nums[i]]);
        }

        return -1;  //�����⣬�������е����Ϊ���������Ҫ�󣬱��뷵��ֵ��
    }
}; 
