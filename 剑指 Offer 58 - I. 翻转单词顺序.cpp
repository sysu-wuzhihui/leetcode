//剑指 Offer 58 - I. 翻转单词顺序
//双指针分词，然后倒序 
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return "";
        string ret;
        for (int i = s.size() - 1; i >= 0;)
        {
            if (s[i] == ' ')
                --i;
            else
            {
                int j = i - 1;
                while (j >= 0 && s[j] != ' ')
                    --j;
                ret = ret + ' ' + s.substr(j + 1, i - j);	//耗内存，耗时 
                i = j;
            }
        }

        if (ret.empty())
            return "";
        return ret.substr(1);
    }
};

//改进上面代码字符串相加耗时耗内存
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return "";
        stringstream ret;
        for (int i = s.size() - 1; i >= 0;)
        {
            if (s[i] == ' ')
                --i;
            else
            {
                int j = i - 1;
                while (j >= 0 && s[j] != ' ')
                    --j;
                ret << ' ' << s.substr(j + 1, i - j);
                i = j;
            }
        }

        if (ret.str().empty())
            return "";
        return ret.str().substr(1);
    }
}; 

//用stringstream来分词
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res, tmp;
        while (ss >> tmp)
            res = tmp + ' ' + res;	//耗内存，耗时 
  		if (res.empty())
			return res; 
        return res.substr(0, res.size() - 1);
    }
}; 
 
