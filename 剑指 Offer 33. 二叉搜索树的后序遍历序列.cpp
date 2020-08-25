//��ָ Offer 33. �����������ĺ����������
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int left = 0, right = postorder.size() - 1;
        return helper(postorder, left, right);
    }

    bool helper(vector<int>& postorder, int left, int right)
    {
        if (left >= right)
            return true;
        int root = postorder[right];    //��ȡ��ֵ
        if (root > postorder[right - 1])    //�����������
        {
            int i = right - 1;
            while (i >= left)
            {
                if (postorder[i] > root)
                    return false;
                --i;
            }

            return helper(postorder, left, right - 1);
        }
        else    //�����������
        {
            int i = right - 1;
            while (i >= left && postorder[i] > root)
                --i;
            int j = i;
            while (i >= left)
            {
                if (postorder[i] > root)
                    return false;
                --i;
            }

            return helper(postorder, left, j) && helper(postorder, j + 1, right - 1);
        }
    }
};

//������������д�� 
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size() - 1);
    }

    bool helper(vector<int>& postorder, int left, int right)
    {
        if (left >= right)
            return true;
        int root = postorder[right];    //��ȡ��ֵ
        int i = left;
        while (postorder[i] < root)    //�����������ڵ�
            ++i;
        int j = i;
        while (postorder[j] > root)    //�����������ڵ�
            ++j;

        return j == right && helper(postorder, left, i - 1) && helper(postorder, i, right - 1);
    }
    
}; 
