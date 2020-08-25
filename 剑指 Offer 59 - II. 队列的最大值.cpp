//剑指 Offer 59 - II. 队列的最大值
//使用一个辅助双端队列 
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (data.empty())
            return -1;
        return maxSave.front();
    }
    
    void push_back(int value) {
        while (!maxSave.empty() && value > maxSave.back())
            maxSave.pop_back();
        maxSave.push_back(value);       
        data.push(value);

    }
    
    int pop_front() {
        if (data.empty())
            return -1;
        if (data.front() == maxSave.front())       
            maxSave.pop_front();    
        int res = data.front();   
        data.pop();

        return res;
    }

private:
    queue<int> data;
    deque<int> maxSave;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */ 
