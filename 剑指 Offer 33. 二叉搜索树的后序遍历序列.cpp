//剑指 Offer 33. 二叉搜索树的后序遍历序列
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
        int root = postorder[right];    //获取根值
        if (root > postorder[right - 1])    //无右子树情况
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
        else    //有右子树情况
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

//上面代码的优雅写法 
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size() - 1);
    }

    bool helper(vector<int>& postorder, int left, int right)
    {
        if (left >= right)
            return true;
        int root = postorder[right];    //获取根值
        int i = left;
        while (postorder[i] < root)    //划分左子树节点
            ++i;
        int j = i;
        while (postorder[j] > root)    //划分右子树节点
            ++j;

        return j == right && helper(postorder, left, i - 1) && helper(postorder, i, right - 1);
    }
    
}; 
