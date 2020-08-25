//剑指 Offer 68 - II. 二叉树的最近公共祖先
//后序遍历，找到p，q节点，向上传递，当某节点左右节点传递上来的节点都不为空，说明该节点为最近父节点，向上返回结果，否则说明最近父节点在左子树或者右子树。 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;	//这种情况，不一定是最终结果。 
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;	//这种情况，一定是最终结果 
		return left ? left : right; 
    }
}; 

