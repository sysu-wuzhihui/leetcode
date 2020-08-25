//剑指 Offer 55 - II. 平衡二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //简单递归，复杂度为o(nlogn) 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
}; 

//计算树高的时候，直接判断树是否平衡，实现剪枝，复杂度o(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        return height(root) != -1;  //直接在计算树高的时候，判断是否平衡
    }

    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        int l = height(root->left);
        if (l == -1)	//一旦检测到不满足条件，立即返回，不用再计算右子树 
            return -1;
        int r = height(root->right);
        if (r == -1)
            return -1;
        
        return abs(l - r) <= 1 ? 1 + max(l, r) : -1;
    }
}; 
