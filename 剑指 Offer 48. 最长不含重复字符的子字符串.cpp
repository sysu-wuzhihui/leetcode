//��ָ Offer 48. ������ظ��ַ������ַ���
//�򵥱���������ѭ�������Ӷ�0(n^3) 
//�����ϣ���ѯ�Ż����ж��ظ��ַ�Ϊo(1)����˸��Ӷ�Ϊo(n^2) 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        int res = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            unordered_set<char> us;
            us.insert(s[i]);
            for (int j = i + 1; j < s.size() && us.find(s[j]) == us.end(); ++j)
            {
                
                us.insert(s[j]);
            
            }

            res = res >= us.size() ? res : us.size();
        }

        return res;
    }
};

//�������ڼӹ�ϣ�����Ӷ�o(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        vector<int> table(128, -1);
        int i = -1, j = 0, res = 1;
        while (j < s.size())
        {
            i = max(i, table[s[j]]);	//i+1 �� j һ�����ظ� 
            res = max(res, j - i);
            table[s[j]] = j;
            ++j;
        }

        return res;
    }
}; 
