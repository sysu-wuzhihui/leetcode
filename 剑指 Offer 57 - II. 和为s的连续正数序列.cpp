//��ָ Offer 57 - II. ��Ϊs��������������
//ֱ����ѧ���㣬���Ӷ�o(n)
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<int> nums(target / 2 + 2);
        for (int i = 1; i < nums.size(); ++i)
            nums[i] = i;
        vector<vector<int>> ret;
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            int j = helper(i, target);
            if ((i + j) * (j - i + 1) / 2 == target)	//����j�Ƿ�����Ҫ�� 
                ret.push_back({nums.begin() + i, nums.begin() + j + 1});
        }

        return ret;
    }

    int helper(long long i, int target)	//һԪ���η�����⡣sqrt��������o(n)���Ӷȣ�����Ӳ�������һ����Χ�ڣ��ǳ���ʱ�� 
    {
        long long a = 1, b = 1, c = i - i * i - 2 * target;
        return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    }
}; 

//�������� 
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target < 3)
            return {};
        vector<vector<int>> res;
        int i = 1, j = 2;
        int count;
        while (i < j)
        {
            count = (i + j) * (j - i + 1) / 2;	//�Ȳ�������� 
                
            if (count == target)
            {
                vector<int> tmp(j - i + 1);
                for (int k = 0; k < tmp.size(); ++k)
                    tmp[k] = i + k;
                res.push_back(tmp);
                i += 2;
                ++j;
            }
            else if (count > target)
                ++i;
            else
                ++j;
        }

        return res;
    }
};

//���õ�һ��ʵ�֣��������Ȳ�������ͣ���������������������� 
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target < 3)
            return {};
        vector<vector<int>> res;
        int i = 1, j = 2;
        int count = 3;	//���ں� 
        while (i < j && i <= target / 2)
        {
            if (count == target)
            {
                vector<int> tmp(j - i + 1);
                for (int k = 0; k < tmp.size(); ++k)
                    tmp[k] = i + k;
                res.push_back(tmp);
                i += 2;
                ++j;               
                count = count - (i - 2) - (i - 1) + j;
            }
            else if (count > target)
            {
                count -= i;                
                ++i;             
            }
            else
            {
                ++j;
                count += j;
            }
        }

        return res;
    }
}; 
