//剑指 Offer 63. 股票的最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int res = 0;
        for (int i = 0, j = 1; j < prices.size(); ++j)	//i指向股票最低价格，j遍历数组，更新i和最大利润 
        {
            if (prices[j] > prices[i])
                res = max(res, prices[j] - prices[i]);
            else
                i = j;
        }

        return res;
    }
}; 

//更简洁的实现
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int ret = 0, buy = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            ret = max(ret, prices[i] - buy);
            buy = min(buy, prices[i]);
        }

        return ret;
    }
}; 
