//剑指 Offer 56 - I. 数组中数字出现的次数
//分组异或
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for (int i : nums)	//结果为两个不同数的异或 
            tmp ^= i;
        int index = 0;
        while (((tmp >> index) & 1) == 0)	//取为1的某位，以此可以将数据分两组，并且两个不同的数分别在两组中。注意==优先级高于>> 
            ++index;
        vector<int> res(2, 0);
        for (int i : nums)	//分组异或 
        {
            if ((i >> index) & 1)
                res[0] ^= i;
            else
                res[1] ^= i;
        }
        
        return res;
    }
}; 

//位操作技巧
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for (int i : nums)
            tmp ^= i;
        int lowBit = tmp & (-tmp);  //技巧，最后一位的1
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
