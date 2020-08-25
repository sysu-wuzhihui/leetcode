//剑指 Offer 50. 第一个只出现一次的字符
//哈希统计，根据题意自定义一个数组哈希表，提高效率 
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
