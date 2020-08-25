//��ָ Offer 09. ������ջʵ�ֶ���
//һ��ջ����push��һ��ջ����pop��������ջ�������ջ�պ��Ƕ���˳��
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
