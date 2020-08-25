//剑指 Offer 64. 求1+2+…+n
//逻辑运算符的短路性质 
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

//更优雅的实现
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};

//俄罗斯农名乘法（快速乘） 
class Solution {
public:
    int sumNums(int n) {
        int a = n, b = n + 1;
        int res = 0;
        a & 1 && (res += b);	//n<=10000,操作14位即可 
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
 
