//��ָ Offer 64. ��1+2+��+n
//�߼�������Ķ�·���� 
class Solution {
public:
    int sumNums(int n) {
        int res = 0;
        helper(n, res);
        return res;
    }

    bool helper(int n, int& res)
    {
        res += n;
        return n > 0 && helper(n - 1, res);
    }
};

//�����ŵ�ʵ��
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};

//����˹ũ���˷������ٳˣ� 
class Solution {
public:
    int sumNums(int n) {
        int a = n, b = n + 1;
        int res = 0;
        a & 1 && (res += b);	//n<=10000,����14λ���� 
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        a & 1 && (res += b);
        a >>= 1;
        b <<= 1;
        

        return res >> 1;
    }
};
 
