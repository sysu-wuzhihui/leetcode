//½£Ö¸ Offer 05. Ìæ»»¿Õ¸ñ
//c++ 
class Solution {
public:
    string replaceSpace(string s) {
        int len = s.size();
        if (len == 0)
            return s;
        string res;
        for (char c : s)
        {
            if (c == ' ')
                res += "%20";
            else
                res += c;
        }

        return res;
    }
};

//c
char* replaceSpace(char* s){
	int length = strlen(s);
	int addLen = 0;
	for (int i = 0; i < length; ++i)
	{
		if (s[i] == ' ')
			addLen += 2;
	}
	length = length + addLen;
	char *res = (char *)malloc(sizeof(char) * (length + 1));
	res[length--] = '\0';
	for (int j = strlen(s) - 1; j >= 0; --j)
	{
		if (s[j] == ' ')
		{
			res[length--] = '0';
			res[length--] = '2';
			res[length--] = '%'; 
		}
		else
		{
			res[length--] = s[j];
		}	
	}

    return res;
}
