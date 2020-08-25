//剑指 Offer 67. 把字符串转换成整数
class Solution {
public:
    int strToInt(string str) {
        if (str.size() == 0)
            return 0;
        int index = 0, len = str.size();
        while (index < len && isspace(str[index]))
            ++index;
        if (index >= len)
            return 0;
        bool neg = false;
        if (str[index] != '-' && str[index] != '+' && !isdigit(str[index]))
            return 0;
        if (str[index] == '+')
            ++index;
        else if (str[index] == '-')
        {
            neg = true;
            ++index;
        }
        int res = 0;
        while (index < len && isdigit(str[index]))
        {
        	//整数溢出处理 
            if (res > INT_MAX / 10)
                return neg ? INT_MIN : INT_MAX;
            if (res == INT_MAX / 10)
            {
                if (!neg && str[index] - '0' >= INT_MAX % 10)
                    return INT_MAX;
                if (neg && str[index] - '0' >= INT_MAX % 10 + 1)
                    return INT_MIN;
            }
            res *= 10;
            res += str[index] - '0';
            ++index;
        }

        return neg ? res * -1 : res;
    }
};

//优雅实现
class Solution {
public:
    int strToInt(string str) {
        if (str.empty())
            return 0;
        int index = 0;
        while (index < str.size() && isspace(str[index]))
            ++index;
        if (index >= str.size() || str[index] != '-' && str[index] != '+' && !isdigit(str[index]))
            return 0;
        bool flag = 0;
        if (!isdigit(str[index]))
        {
            flag = str[index] == '-';
            ++index;
            if (index >= str.size())
                return 0;
        }
        int ret = 0;
        while (index < str.size() && isdigit(str[index]))
        {
        	//溢出标准处理方法 
            if (ret > INT_MAX / 10 || ret == INT_MAX / 10 && (str[index] - '0') > INT_MAX % 10)
                return flag ? INT_MIN : INT_MAX;
            ret = ret * 10 + (str[index] - '0');
            ++index;
        }
    
        return flag ? -ret : ret;
    }
};
