//��ָ Offer 66. �����˻�����
//�Գ���ˣ����α���
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty())
            return {};
        vector<int> res(a.size(), 1);
        int left = 1, right = 1;
        for (int i = 0; i < a.size(); ++i)
        {
            res[i] *= left;
            left *= a[i];
        }
        for (int j = a.size() - 1; j >= 0; --j)
        {
            res[j] *= right;
            right *= a[j];
        }

        return res;
    }
}; 

//һ�α�������
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty())
            return {};
        vector<int> res(a.size(), 1);
        int left = 1, right = 1;
        for (int i = 0; i < a.size(); ++i)
        {
            res[i] *= left;
            left *= a[i];
            res[a.size() - 1 - i] *= right;
            right *= a[a.size() - 1 - i];
        }

        return res;
    }
}; 
