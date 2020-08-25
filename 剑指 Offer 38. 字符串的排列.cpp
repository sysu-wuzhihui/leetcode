//½£Ö¸ Offer 38. ×Ö·û´®µÄÅÅÁÐ
//dfs
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        dfs(s, 0, res);
        return res;
    }

    void dfs(string& s, int pos, vector<string>& res)
    {
        if (pos == s.size() - 1)
        {
            res.push_back(s);
            return;
        }
        
        unordered_set<char> us;	
        for (int i = pos; i < s.size(); ++i)
        {
            if (us.find(s[i]) == us.end())
            {
                us.insert(s[i]);
                swap(s[pos], s[i]);
                dfs(s, pos + 1, res);
                swap(s[pos], s[i]);
            }      
        }
    }
}; 
