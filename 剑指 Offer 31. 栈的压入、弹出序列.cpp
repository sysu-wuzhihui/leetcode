//剑指 Offer 31. 栈的压入、弹出序列
//模拟入栈出栈
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) 
            return false;
        stack<int> st;
        for (int i = 0, j = 0; i < pushed.size(); ++i)
        {
            st.push(pushed[i]);
            while (!st.empty() && popped[j] == st.top())
            {
                st.pop();
                ++j;
            }
        }

        return st.empty();
    }
};

//另一种思路，后一个出栈的元素，在压栈时候的位置，只能在前面一个元素的后面，或者在其前面但中间不能跨过未出栈的元素
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size())
            return false;
        int lastPop = -1;	//记录上一个出栈元素位置 
        for (int i = 0; i < popped.size(); ++i)
        {
            for (int j = 0; j < pushed.size(); ++j)
            {
                if (pushed[j] == popped[i])
                {
                    pushed[j] = -1;	//标记已出栈 
                    for (int k = j + 1; k < lastPop; ++k)
                        if (pushed[k] != -1)	//不能在上一个出栈元素前面且跨过未出栈的元素 
                            return false;
                    lastPop = j;
                }
            }
        }

        return true;
    }
}; 
