//剑指 Offer 41. 数据流中的中位数
//插入排序，复杂度o(n^2) 
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        data.push_back(num);
        int i = data.size() - 2;
        while (i >= 0 && data[i] > num)
        {
            data[i + 1] = data[i];
            --i;
        }      
        data[i + 1] = num;
    }
    
    double findMedian() {
        if (data.size() % 2)
            return data[data.size() / 2];
        return (data[data.size() / 2 - 1] + data[data.size() / 2]) / 2.0;
    }

    vector<int> data;
};

//用两个堆，分别保存较大一半和较小一半的数据，复杂度o(nlongn)
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (big.size() == small.size())
        {
            small.push(num);
            int val = small.top();
            small.pop();
            big.push(val);
        }
        else
        {
            big.push(num);
            int val = big.top();
            big.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        return big.size() == small.size() ? (big.top() + small.top()) / 2.0 : big.top();
    }

    priority_queue<int, vector<int>, less<int>> big;	//小顶堆，保存较大的一半 
    priority_queue<int, vector<int>, greater<int>> small;	//大顶堆，保存较小的一半 
};

//上述代码性能改进
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (small.empty())
            small.push(num);
        else if (small.size() == big.size())
        {
            if (num > big.top())	//进行判断决定是否在两边进行堆调整 
            {
                small.push(big.top());
                big.pop();
                big.push(num);
            }
            else
                small.push(num);	//只在一边进行堆调整 
        }
        else
        {
            if (num < small.top())
            {
                big.push(small.top());
                small.pop();
                small.push(num);
            }
            else
                big.push(num);
        }
    }
    
    double findMedian() {
        if (small.size() > big.size())
            return small.top();
        return (small.top() + big.top()) / 2.0;
    }

    priority_queue<int, vector<int>, less<int>> small;
    priority_queue<int, vector<int>, greater<int>> big;
}; 


