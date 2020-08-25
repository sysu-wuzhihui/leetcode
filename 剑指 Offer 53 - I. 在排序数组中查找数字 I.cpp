//��ָ Offer 53 - I. �����������в������� I 
//���ֲ��ҷ�Ϊ�򵥶��֣�������߽磬�����ұ߽�ȣ���Ҫע��ϸ�ڡ�ѭ���������ж��������߽���������ؼ�����Ҫע������ 
//һ�ζ��ֲ��ң�Ȼ�����Ի������� 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1)
            return 0;
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        if (nums[mid] != target)
            return 0;
        int i = mid, j = mid;
        while (i > 0 && nums[i - 1] == target)
            --i;
        while (j < nums.size() - 1 && nums[j + 1] == target)
            ++j;
        return j - i + 1;
    }
};

//���ζ��ֲ��ң�Ѱ�����ұ߽�
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1)
            return 0;
        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;  //midƫ��
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        int left = r;   //��߽�
       
        if (l >= nums.size() || nums[l] != target)  //û���ҵ�����ǰ����
            return 0;
        l = 0;
        r = nums.size() - 1;
        while (l < r)
        {
            mid = l + (r - l + 1) / 2;  //midƫ��
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        int right = l;  //�ұ߽硣�������ж�target�Ƿ�����ˣ���������߽��Ѿ��ж���

        return right - left + 1;
    }
};
