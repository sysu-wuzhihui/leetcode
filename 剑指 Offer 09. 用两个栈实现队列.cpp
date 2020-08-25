//剑指 Offer 09. 用两个栈实现队列
//一个栈用来push，一个栈用来pop，从输入栈倒进输出栈刚好是队列顺序
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if (out.empty())
        {
            if (in.empty())
                return -1;
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        int res = out.top();
        out.pop();
        return res;
    }

    stack<int> in, out;
};
