//��ָ Offer 56 - I. ���������ֳ��ֵĴ���
//�������
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for (int i : nums)	//���Ϊ������ͬ������� 
            tmp ^= i;
        int index = 0;
        while (((tmp >> index) & 1) == 0)	//ȡΪ1��ĳλ���Դ˿��Խ����ݷ����飬����������ͬ�����ֱ��������С�ע��==���ȼ�����>> 
            ++index;
        vector<int> res(2, 0);
        for (int i : nums)	//������� 
        {
            if ((i >> index) & 1)
                res[0] ^= i;
            else
                res[1] ^= i;
        }
        
        return res;
    }
}; 

//λ��������
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for (int i : nums)
            tmp ^= i;
        int lowBit = tmp & (-tmp);  //���ɣ����һλ��1
        vector<int> res(2, 0);
        for (int i : nums)
        {
            if (i & lowBit)
                res[0] ^= i;
            else
                res[1] ^= i;
        }
        
        return res;
    }
}; 
