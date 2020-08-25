//��ָ Offer 20. ��ʾ��ֵ���ַ���
//�������������жϣ�˼ά���̶ܳȡ����õķ�������״̬������ 
class Solution {
public:
    bool isNumber(string s) {
        if (s.empty())
            return false;
        int length = s.size();
        bool frac = false;  //����С����ֻ��һ��
        int i = 0;

        //ȥ��ͷβ�Ŀհ��ַ�
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

//״̬��
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
        while (len > 0 && s[len - 1] == ' ')	//ȥ��β���ո� 
            --len;
        int cur = 0;	//��ʼ״̬ 
        for (int i = 0; i < len; ++i)
        {
            char c = s[i];
            if (isdigit(c))
                c = 'n';	//���� 
            else if (c == '+' || c == '-')
                c = 's';	//���� 
            else if (c == '.')
                c = 'd';	//С���� 
            else if (c == ' ')
                c = 'b';	//�ո� 
            else if (c == 'e')
                c = 'e';	//e 
            else 
                c = '?';	//�������š�ֱ���˳�������false 
            if (state[cur].find(c) == state[cur].end())
                return false;
            cur = state[cur][c];	//��һ��״̬ 
        }

        return cur == 2 || cur == 4 || cur == 6 || cur == 8 || cur == 9;  
    }
}; 
