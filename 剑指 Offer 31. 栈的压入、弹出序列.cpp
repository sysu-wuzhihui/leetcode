//��ָ Offer 31. ջ��ѹ�롢��������
//ģ����ջ��ջ
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

//��һ��˼·����һ����ջ��Ԫ�أ���ѹջʱ���λ�ã�ֻ����ǰ��һ��Ԫ�صĺ��棬��������ǰ�浫�м䲻�ܿ��δ��ջ��Ԫ��
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size())
            return false;
        int lastPop = -1;	//��¼��һ����ջԪ��λ�� 
        for (int i = 0; i < popped.size(); ++i)
        {
            for (int j = 0; j < pushed.size(); ++j)
            {
                if (pushed[j] == popped[i])
                {
                    pushed[j] = -1;	//����ѳ�ջ 
                    for (int k = j + 1; k < lastPop; ++k)
                        if (pushed[k] != -1)	//��������һ����ջԪ��ǰ���ҿ��δ��ջ��Ԫ�� 
                            return false;
                    lastPop = j;
                }
            }
        }

        return true;
    }
}; 
