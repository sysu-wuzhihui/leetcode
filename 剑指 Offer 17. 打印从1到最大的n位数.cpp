//��ָ Offer 17. ��ӡ��1������nλ��������Ǵ����Ļ�������Ҫ�õ��ַ�������ʾ�����ʱ��������������ȫ����������Ҳ������һ�����ַ������� 
class Solution {
public:
    vector<int> printNumbers(int n) {
        int total = pow(10, n) - 1;
        vector<int> res(total);
        for (int i = 0; i < total; ++i)
            res[i] = i + 1;
        return res;
    }
}; 
