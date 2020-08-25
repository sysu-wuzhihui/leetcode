//��ָ Offer 58 - I. ��ת����˳��
//˫ָ��ִʣ�Ȼ���� 
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
                ret = ret + ' ' + s.substr(j + 1, i - j);	//���ڴ棬��ʱ 
                i = j;
            }
        }

        if (ret.empty())
            return "";
        return ret.substr(1);
    }
};

//�Ľ���������ַ�����Ӻ�ʱ���ڴ�
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

//��stringstream���ִ�
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res, tmp;
        while (ss >> tmp)
            res = tmp + ' ' + res;	//���ڴ棬��ʱ 
  		if (res.empty())
			return res; 
        return res.substr(0, res.size() - 1);
    }
}; 
 
