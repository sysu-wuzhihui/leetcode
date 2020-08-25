//��ָ Offer 30. ����min������ջ
//�ؼ����ڱ�����ʷ��Сֵ��ʹ��һ������ջ��������ʷ��Сֵ 
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (minData.empty() || x <= minData.top())
            minData.push(x);
        data.push(x);
    }
    
    void pop() {
        if (data.top() == minData.top())
            minData.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return minData.top();
    }

    stack<int> data, minData;
};

//��ʹ�ø���ջ��Ч�ʸ��� 
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (data.empty())
        {
            minVal = x;
            data.push(x);
        }
        else if (x <= minVal)
        {
            data.push(minVal);	//ѹ����һ����Сֵ 
            data.push(x);
            minVal = x;
        }
        else
        {
            data.push(x);
        }
            
    }
    
    void pop() {
        if (!data.empty())
        {
            if (data.top() == minVal)
            {
                data.pop();
                //ע���������Ҫ��һ���п� 
                if (!data.empty())
                {
                    minVal = data.top();
                    data.pop();
                }
                
            }
            else
            {
                data.pop();
            }
        }
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return minVal;
    }

    int minVal;
    stack<int> data;
};

//�Ż�����ĳ���
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal =  INT_MAX;
    }
    
    void push(int x) {
        if (x <= minVal)
        {
            data.push(minVal);
            minVal = x;
        }
        data.push(x);
    }
    
    void pop() {
        if (!data.empty())
        {
            if (data.top() == minVal)
            {
                data.pop();
                minVal = data.top();
            }
            data.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return minVal;
    }

    stack<int> data;
    int minVal;
};

