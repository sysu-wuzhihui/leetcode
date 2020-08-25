//��ָ Offer 59 - I. �������ڵ����ֵ
//�������Ľ���ƽ�����Ӷ�o(n)����ǵ������飬���Ӷ�o(nk)���������ö��Ҵ�������������Ӷ�Ϊo(nlogk) 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())	//�߽��ж� 
            return {};
        vector<int> res(nums.size() - k + 1);	//������� 
        
        //�ҵ���һ����������ֵ 
        res[0] = nums[0];
        for (int i = 1; i < k; ++i)
            res[0] = max(res[0], nums[i]);
            
        for (int i = 1; i <= nums.size() - k; ++i)
        {
            if (nums[i - 1] == res[i - 1]) //����������һ��������һ�����ڵ����ֵ����Ҫ���±����µĴ��������ֵ 
            {
                res[i] = nums[i];
                for (int j = i + 1; j < i + k; ++j)
                    res[i] = max(nums[j], res[i]);
            }
            else	//��һ���������ֵ���ڵ�ǰ�����У�ֻ��Ƚ��Ҳ��¼����ֵ�͸����ֵ���ɡ������˶�̬�滮˼�룬����ÿ�ζ���������Ѱ�����ֵ���������ǴӴ�С��������飬��ʱÿ�ζ��ñ������� 
                res[i] = max(res[i - 1], nums[i + k - 1]);
        }
            
        return res;
    }
}; 

//�����У��е�������Сջ��ʹ��˫�˶��У����Ӷ�o(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < 2 || k == 1)
            return nums;
        deque<int> dq;	//�������� 
        vector<int> ret(nums.size() - k + 1);
        for (int i = 0, j = 0; i < nums.size(); ++i)
        {
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            
            if (i - dq.front() == k)	//��ͷ�Ƴ��˴��� 
                dq.pop_front();
            if (i >= k - 1)	//�γɴ��ڣ���ʼ������ 
                ret[j++] = nums[dq.front()];
        }

        return ret;
    }
};
