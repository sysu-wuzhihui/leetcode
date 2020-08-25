//剑指 Offer 44. 数字序列中某一位的数字
//简单思路，n较大时会超内存
class Solution {
public:
    int findNthDigit(int n) {
        stringstream ss;
        int i = 0;
        while (n >= ss.str().size())
            ss << i++;
        return ss.str()[n] - '0';
    }
};
 
//找规律，按照一位，两位，三位等包含的整数，先确定n在几位数字中，再确定具体的数，再确定具体第几位
class Solution {
public:
    int findNthDigit(int n) {
        int base = 1, tmp = 9, num = 1;	//base：某类数的第一个，tmp：某类数的总数，num：位数 
        while (n > (tmp * num))	//第一步，找出在几位数的数类中 
        {
            n -= (tmp * num);
            ++num;
            tmp *= 10;
            base *= 10;
            if (tmp > INT_MAX / num)	//提前跳出，防止溢出 
                break;
        }
        int digit = (n - 1) / num + base;	//第二步，确定具体的数字 
        string s = to_string(digit);
        return s[(n - 1) % num] - '0';	//第三步，确定具体的位 
    }
};
