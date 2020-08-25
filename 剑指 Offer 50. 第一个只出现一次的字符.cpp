//��ָ Offer 50. ��һ��ֻ����һ�ε��ַ�
//��ϣͳ�ƣ����������Զ���һ�������ϣ�����Ч�� 
class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty())
            return ' ';
        int table[26] = {0};
        for (char c : s)
            ++table[c - 'a'];
        for (char c : s)
            if (table[c - 'a'] == 1)
                return c;
        return ' ';
    }
};
