//剑指 Offer 26. 树的子结构
//涉及树，一般都是递归做
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B || !A)
            return false;
        return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool helper(TreeNode* a, TreeNode* b)
    {
        if (!b)
            return true;
        if (!a || a->val != b->val)
            return false;
        return helper(a->left, b->left) && helper(a->right, b->right);
    }
};
