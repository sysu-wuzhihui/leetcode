//��ָ Offer 53 - II. 0��n-1��ȱʧ������
//�������飬���Ƕ��ֲ��ҡ�����ȱʧ����֮��Ĳ��֣�nums[index]>index,ǰ������nums[index]==index 

//o(n)�������� 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            if (i != nums[i])
                return i;

        return nums.size();
    }
};

 
//���ֲ��� 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right)	//����ѭ��ʱ��leftָ����߲����ұߵ���һ��λ�ã���ȱʧ������rightָ����߲������һ���� 
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > mid)    //Ҳ����nusm[mid] != mid
                right = mid - 1;
            else    //nums[mid] == mid, �����ܴ���nums[mid] < mid
                left = mid + 1; 
        }

        return left;
    }
};

//���ֲ��ң�����߲��ֵ��ұ߽�
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = -1, r = nums.size() - 1;	//��߲��ֿ��ܲ����ڣ�����l��ʼΪ-1 
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;	//ע������mid���ҿ� 
            if (mid == nums[mid])
                l = mid;
            else
                r = mid - 1;
        }

        return l + 1;
    }
};

//���ֲ��ң����ұ߲��ֵ���߽�
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size();	//�ұ߲��ֿ��ܲ����ڣ�����r��ʼΪnums.size() 
        while (l < r)
        {
            int mid = l + (r - l) / 2;	//ע���������� 
            if (mid == nums[mid])
                l = mid + 1;
            else
                r = mid;
        }

        return l;	//ע�����ﷵ�ز���l-1 
    }
};
 
