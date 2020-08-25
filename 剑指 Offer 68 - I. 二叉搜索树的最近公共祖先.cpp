//剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
//递归实现 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

//迭代实现
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true)
        {
            if (p->val > root->val && q->val > root->val)
                root = root->right;
            else if (p->val < root->val && q->val < root->val)
                root = root->left;
            else
                return root;
        }

        return NULL;
    }
};
