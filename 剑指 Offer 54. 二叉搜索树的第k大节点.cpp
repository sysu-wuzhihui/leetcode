//剑指 Offer 54. 二叉搜索树的第k大节点
//中序遍历输出到数组中，再反向查找 
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        int j = v.size();
        while (k-- > 0)
            --j;
        return v[j];
    }

    void inorder(TreeNode* root, vector<int>& v)
    {
        if (!root)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};

//反中序遍历，遍历过程中找到目标，且可以提前返回 
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int ret;
        inorder(root, k, ret);
        return ret;
    }

    void inorder(TreeNode* root, int& k, int& ret)
    {
        if (!root)
            return;
        inorder(root->right, k, ret);
        if (k == 0)	//提前返回 
            return;
        if (k == 1)
            ret = root->val;
        --k;
        inorder(root->left, k, ret);
    }
}; 

//非递归遍历树
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int res;
        stack<TreeNode*> st;
        while (root || !st.empty())
        {
            if (root)
            {
                st.push(root);
                root = root->right;
            }
            else
            {
                root = st.top();
                st.pop();
                if (--k == 0)
                {
                    res = root->val;
                    break;
                }
                root = root->left;
            }
        }
        return res;
    }
}; 
