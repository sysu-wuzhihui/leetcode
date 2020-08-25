//剑指 Offer 20. 表示数值的字符串
//考察各种情况的判断，思维严密程度。更好的方法是用状态机来做 
class Solution {
public:
    bool isNumber(string s) {
        if (s.empty())
            return false;
        int length = s.size();
        bool frac = false;  //控制小数点只有一个
        int i = 0;

        //去除头尾的空白字符
        while (isspace(s[i]))
            ++i;
        while (length > 0 && isspace(s[length - 1]))
            --length;

        if (length <= 0)
            return false;
        if (s[i] == '+' || s[i] == '-')
            ++i;
        if (i == length)
            return false;
        if (!isdigit(s[i]) && s[i] != '.')
            return false;
        if (s[i] == '.')
        {
            ++i;
            frac = true;
        }
            
        if (i == length)
            return false;
        while (i < length && isdigit(s[i]))
            ++i;
        if (i == length)
            return true;
        if (s[i] != '.' && s[i] != 'e' && s[i] != 'E')
            return false;
        if (s[i] == '.')
        {
            if (frac)
                return false;
            ++i;

            while (i < length && isdigit(s[i]))
                ++i;
            if (i == length)
                return true;
            if (s[i] != 'e' && s[i] != 'E')
                return false;

            ++i;
            if (i == length)
                return false;
            if (s[i] == '-' || s[i] == '+')
                ++i;
            while (i < length)
                if (!isdigit(s[i++]))
                    return false;
            return true;
        }
        else 
        {
            if (!isdigit(s[i - 1]))
                return false;
            ++i;
            if (s[i] == '-' || s[i] == '+')
                ++i;
            if (i == length)
                return false;

            while (i < length)
                if (!isdigit(s[i++]))
                    return false;
            return true;
        }
    }
}; 

//状态机
class Solution {
public:
    bool isNumber(string s) {
        if (s.empty())
            return false;
        vector<map<char, int>> state = 
        {
            {{'b', 0}, {'s', 1}, {'n', 2}, {'d', 3}},
            {{'n', 2}, {'d', 3}},
            {{'n', 2}, {'d', 4}, {'e', 5}},
            {{'n', 6}},
            {{'n', 6}, {'e', 5}},
            {{'s', 7}, {'n', 8}},
            {{'n', 6}, {'e', 5}},
            {{'n', 9}},
            {{'n', 8}},
            {{'n', 9}}
        };

        int len = s.size();
        while (len > 0 && s[len - 1] == ' ')	//去除尾部空格 
            --len;
        int cur = 0;	//初始状态 
        for (int i = 0; i < len; ++i)
        {
            char c = s[i];
            if (isdigit(c))
                c = 'n';	//数字 
            else if (c == '+' || c == '-')
                c = 's';	//符号 
            else if (c == '.')
                c = 'd';	//小数点 
            else if (c == ' ')
                c = 'b';	//空格 
            else if (c == 'e')
                c = 'e';	//e 
            else 
                c = '?';	//其它符号。直接退出，返回false 
            if (state[cur].find(c) == state[cur].end())
                return false;
            cur = state[cur][c];	//下一个状态 
        }

        return cur == 2 || cur == 4 || cur == 6 || cur == 8 || cur == 9;  
    }
}; 
