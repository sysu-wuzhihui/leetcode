//��ָ Offer 45. �������ų���С����
//�Զ���һ������ȽϺ�������
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){ return to_string(a) + to_string(b) < to_string(b) + to_string(a); });
        stringstream ss;
        for (int data : nums)
            ss << data;
        return ss.str();
    }
};
