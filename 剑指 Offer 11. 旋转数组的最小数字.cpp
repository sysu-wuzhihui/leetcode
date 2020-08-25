//��ָ Offer 11. ��ת�������С����
//���ֲ��ҡ����ֲ�����Ҫ�أ�ѭ���������ж��������߽����� 
//����ı��ʣ��������������������������������ʼֵ����������������С�ڵ�������������
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        if (len < 2)
            return numbers[0];
        int left = 0, right = len - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[right])	//mid������������ 
                left = mid + 1;
            else if (numbers[mid] < numbers[right])	//mid������������ 
                right = mid;
            else	//�޷�ȷ������ȫ����--j 
                --right;
        }

        return numbers[left];
    }
};
