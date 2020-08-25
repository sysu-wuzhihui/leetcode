//剑指 Offer 48. 最长不含重复字符的子字符串
//简单暴力，三重循环，复杂度0(n^3) 
//加入哈希表查询优化，判断重复字符为o(1)，因此复杂度为o(n^2) 
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

//滑动窗口加哈希表，复杂度o(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        vector<int> table(128, -1);
        int i = -1, j = 0, res = 1;
        while (j < s.size())
        {
            i = max(i, table[s[j]]);	//i+1 到 j 一定不重复 
            res = max(res, j - i);
            table[s[j]] = j;
            ++j;
        }

        return res;
    }
}; 
