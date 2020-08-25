//剑指 Offer 65. 不用加减乘除做加法
class Solution {
public:
    int add(int a, int b) {
        if (b == 0)
            return a;
        
        return add(a ^ b, (a & b & ~(1 << 31)) << 1);   //负数左移报错，手动去除最高位的1.或者转化为无符号数(unsigned int)(a & b) << 1 
    }
};

//迭代
class Solution {
public:
    int add(int a, int b) {
        unsigned int ret = a, step = b;
        while (step)
        {
            int tmp = ret;
            ret ^= step;
            step = (step & tmp) << 1;
        }

        return ret;
    }
};
