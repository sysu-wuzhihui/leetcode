//��ָ Offer 40. ��С��k����
//���ַ����ɽ⣬ֱ�����򣬿���ѡ�񣬶ѣ������������ݷ�Χ���ޣ�
//ֱ������
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty() || k < 1)
            return {};
        sort(arr.begin(), arr.end());

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

//����ѡ����Ҫ�����������ݵ��ڴ��У����ʺϴ����ݣ�����Ҫ�޸�ԭ������ 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty() || k < 1)
            return {};
        return quickSelect(arr, 0, arr.size() - 1, k - 1);
    }

    vector<int> quickSelect(vector<int>& arr, int left, int right, int k)
    {
        int p = partition(arr, left, right);
        if (p == k)
            return vector<int>(arr.begin(), arr.begin() + k + 1);
        if (p < k)
            return quickSelect(arr, p + 1, right, k);
        return quickSelect(arr, left, p - 1, k);
    }

    int partition(vector<int>& arr, int left, int right)
    {
        if (left >= right)
            return left;
        int key = arr[left];
        while (left < right)
        {
            while (right > left && arr[right] > key)
                --right;
            swap(arr[left], arr[right]);
            while (right > left && arr[left] <= key)
                ++left;
            swap(arr[left], arr[right]);
        }
        arr[left] = key;

        return left;
    }
};
 
//��������˼�룬��ҪԪ��ֵ��һ����Χ 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty() || k < 1)
            return {};
        vector<int> count(10001, 0);
        for (int v : arr)
            ++count[v];
        vector<int> ret;
    
        for (int i = 0; k > 0 && i < count.size(); ++i)
        {
            if (count[i] > 0)
            {
                int n = min(k, count[i]);
                ret.insert(ret.end(), n, i);
                k -= n;
            }                  
        }
        
        return ret;
    }
};


//������˼�룬ά��һ���󶥶ѡ�top(k)�����׼�ⷨ������Ҫ�����������ݵ��ڴ��У������ڴ����� 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty() || k <= 0)
            return {};
        vector<int> res;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (i < k)
                pq.push(arr[i]);
            else
            {
                if (arr[i] < pq.top())
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        
        for (int i = 0; i < k; ++i)
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
}; 

