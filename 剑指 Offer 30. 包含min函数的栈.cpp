//剑指 Offer 30. 包含min函数的栈
//关键在于保存历史最小值，使用一个辅助栈来保存历史最小值 
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

//不使用辅助栈，效率更高 
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
            data.push(minVal);	//压入上一个最小值 
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
                //注意这里必须要加一个判空 
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

//优化上面的程序
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

