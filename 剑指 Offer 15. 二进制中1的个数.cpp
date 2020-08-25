//剑指 Offer 15. 二进制中1的个数
//考察位操作
//逐位判断 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0)
        {
            res += n & 0x1;
            n = n >> 1;
        }

        return res;
    }
};

//用n&(n-1) 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0)
        {
            res += 1;
            n = n & (n - 1);    //n - 1:最右侧的1变0,并且之后的0全变1,n&(n-1)相当于把最右侧的1变0,消除一个1，可以用来统计1的个数
        }

        return res;
    }
};

