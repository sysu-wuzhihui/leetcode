//��ָ Offer 10- I. 쳲���������
//1�ݹ飬�����ظ����ú��������Ӷ�o(2^n)
//2���仯�ݹ飬��һ�������¼�м������ռ临�Ӷ�o(n)
//3��̬�滮������ֻ��Ҫǰ������ֵ�Ϳ��Եõ������ֵ�����Կռ临�Ӷ�o(1)

//��̬�滮 
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int a = 0, b = 1;
        int  res;
        while (n-- >= 2)
        {
            res = (a + b) % 1000000007;
            a = b;
            b = res;
        }

        return res;
    }
}; 
