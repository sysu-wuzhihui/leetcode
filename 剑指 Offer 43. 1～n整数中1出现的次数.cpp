//��ָ Offer 43. 1��n������1���ֵĴ���
//curΪ��ǰλ��highΪ��λ��lowΪ��λ�����ֺ���й����ܽ� 
class Solution {
public:
    int countDigitOne(int n) {
        int ret = 0;
        int low = 0, high = n / 10, weight = 1, digit = n % 10;
        while (high || digit)
        {
            if (digit == 0)
                ret += high * weight;
            else if (digit == 1)
                ret += high * weight + low + 1;
            else    
                ret += (high + 1) * weight;

            low += digit * weight;
            digit = high % 10;
            high /= 10;
            if (weight > INT_MAX / 10)
                break;
            weight *= 10;
        }

        return ret;
    }
};
