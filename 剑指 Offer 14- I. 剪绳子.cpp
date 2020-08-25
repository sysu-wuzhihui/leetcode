//��ָ Offer 14- I. ������
//���ַ����ɽ⡣1.�򵥵ݹ飬���ظ����㣬ָ�����Ӷ� 2.���仯�ݹ� 3.��̬�滮 4.��ѧ���ɣ��γ�3Ϊ���ţ�β����3����ע�⴦��һ�¼���
//���仯�ݹ飬�Զ����� 
class Solution {
public:
    int cuttingRope(int n) {
        if (n <2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> save(n + 1, 0);
        return helper(n, save);
    }

    int helper(int n, vector<int>& save)
    {
        if (n < 3)
            return 1;
        if (save[n] > 0)
            return save[n];
        int res = 0;
        for (int i = 1; i < n; ++i)
            res = max(res, max(i * (n - i), i * helper(n - i, save)));
        save[n] = res;
        return res;
    }

};
 
//��̬�滮 ���Ե����ϡ�f(n) = max{i * (n - i), f(n - i) * i}, 1<= i <= n - 1 ,i * (n - i)��ʾ�����Σ�f(n - i) * i ��ʾ���������� 
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            int max = 0;
            
            for (int j = 1; j <= i - 1; ++j)
            {
                if (dp[i - j] * j > max)
                    max = dp[i - j] * j;
                if (j * (i - j) > max)
                    max = j * (i - j);
            }
            dp[i] = max;
            //cout << max << " ";
        }

        return dp[n];
    }
}; 

//��ѧ���ɣ����Խ��������󵼾�ȷ֤��3Ϊ���Ŷγ���������߼�����˵�� �����ڶγ�Ϊ1������ܽ���޹��ף��ų���
//���ڶγ�2���Խ������Ϊ2�������ڶγ�3���Խ������Ϊ3�������ڶγ�4����Խ������Ϊ4������4�����г�2 2 ���Խ������Ҳ��4����˿�����2���
//���ڶγ�5���Խ������Ϊ5���������г�2 3�󣬹���Ϊ6������˿�����2��3�������ͬ�����Ķγ���������2 3�������ȡ�õĽ��������Ƚ�2 �� 3�ĸ�����
//ȡ������С������6����Ϊ2�Ķγ����Ϊ8����Ϊ3���Ϊ9����˶γ�3���ţ���3Ϊ���Ŷγ���
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n - 1;
        int a = n / 3, b = n % 3;
        if (b == 0)
            return pow(3, a);
        if (b == 1)
            return pow(3, a - 1) * 2 * 2;
        if (b == 2)
            return pow(3, a) * 2;
        return -1;
    }
}; 
 
