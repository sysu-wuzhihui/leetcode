//��ָ Offer 62. ԲȦ�����ʣ�µ�����
//�ҹ��ɡ�f(n,m)=y,��ʾʣ���±�Ϊy����0��ʼ������f(n-1,m)=x, ��ʾʣ���±�Ϊx��(m-1)%n��ɾ������m%n��ʼ����
//������y=(m%n+x)%n=(m+x)%n 
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1)
            return 0;
        return (m + lastRemaining(n- 1, m)) % n;
    }
};

//����
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ret = 0;
        for (int i = 2; i <= n; ++i)
            ret = (m + ret) % i;
        return ret;
    }
};
