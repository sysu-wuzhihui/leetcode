//��ָ Offer 44. ����������ĳһλ������
//��˼·��n�ϴ�ʱ�ᳬ�ڴ�
class Solution {
public:
    int findNthDigit(int n) {
        stringstream ss;
        int i = 0;
        while (n >= ss.str().size())
            ss << i++;
        return ss.str()[n] - '0';
    }
};
 
//�ҹ��ɣ�����һλ����λ����λ�Ȱ�������������ȷ��n�ڼ�λ�����У���ȷ�������������ȷ������ڼ�λ
class Solution {
public:
    int findNthDigit(int n) {
        int base = 1, tmp = 9, num = 1;	//base��ĳ�����ĵ�һ����tmp��ĳ������������num��λ�� 
        while (n > (tmp * num))	//��һ�����ҳ��ڼ�λ���������� 
        {
            n -= (tmp * num);
            ++num;
            tmp *= 10;
            base *= 10;
            if (tmp > INT_MAX / num)	//��ǰ��������ֹ��� 
                break;
        }
        int digit = (n - 1) / num + base;	//�ڶ�����ȷ����������� 
        string s = to_string(digit);
        return s[(n - 1) % num] - '0';	//��������ȷ�������λ 
    }
};
