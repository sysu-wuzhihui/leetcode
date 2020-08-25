//剑指 Offer 59 - I. 滑动窗口的最大值
//暴力法改进，平均复杂度o(n)，最坏是倒序数组，复杂度o(nk)。还可以用堆找窗口最大数，复杂度为o(nlogk) 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())	//边界判断 
            return {};
        vector<int> res(nums.size() - k + 1);	//结果数组 
        
        //找到第一个窗口最大的值 
        res[0] = nums[0];
        for (int i = 1; i < k; ++i)
            res[0] = max(res[0], nums[i]);
            
        for (int i = 1; i <= nums.size() - k; ++i)
        {
            if (nums[i - 1] == res[i - 1]) //窗口左侧外第一个数是上一个窗口的最大值，需要重新遍历新的窗口找最大值 
            {
                res[i] = nums[i];
                for (int j = i + 1; j < i + k; ++j)
                    res[i] = max(nums[j], res[i]);
            }
            else	//上一个窗口最大值还在当前窗口中，只需比较右侧新加入的值和该最大值即可。利用了动态规划思想，不用每次都遍历窗口寻找最大值。最坏情况下是从大到小排序的数组，此时每次都得遍历窗口 
                res[i] = max(res[i - 1], nums[i + k - 1]);
        }
            
        return res;
    }
}; 

//最大队列，有点类似最小栈。使用双端队列，复杂度o(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < 2 || k == 1)
            return nums;
        deque<int> dq;	//保存索引 
        vector<int> ret(nums.size() - k + 1);
        for (int i = 0, j = 0; i < nums.size(); ++i)
        {
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            
            if (i - dq.front() == k)	//队头移出了窗口 
                dq.pop_front();
            if (i >= k - 1)	//形成窗口，开始保存结果 
                ret[j++] = nums[dq.front()];
        }

        return ret;
    }
};
