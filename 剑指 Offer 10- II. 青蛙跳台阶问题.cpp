//��ָ Offer 10- II. ������̨������
//���һ������������һ��������е��ƹ�ϵf(n)=f(n-1)+f(n-2)��ת��Ϊ쳲���������
class Solution {
public:
    int numWays(int n) {
        if (n < 2)
            return 1;
        int a = 1, b = 1, res;
        while (n-- >= 2)
        {
            res = (a + b) % 1000000007;
            a = b;
            b = res;
        }

        return res;
    }
};
