//��ָ Offer 63. ��Ʊ���������
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int res = 0;
        for (int i = 0, j = 1; j < prices.size(); ++j)	//iָ���Ʊ��ͼ۸�j�������飬����i��������� 
        {
            if (prices[j] > prices[i])
                res = max(res, prices[j] - prices[i]);
            else
                i = j;
        }

        return res;
    }
}; 

//������ʵ��
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
