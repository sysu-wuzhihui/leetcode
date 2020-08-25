//剑指 Offer 07. 重建二叉树
//按引用传递数组，减少内存使用 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight)
    {
        if (preLeft > preRight)
            return NULL;
        TreeNode* res = new TreeNode(preorder[preLeft]);
        int rootVal = preorder[preLeft];
        int pos = inLeft;
        while (pos <= inRight && inorder[pos] != rootVal)
            ++pos;
        res->left = helper(preorder, preLeft + 1, preLeft + pos - inLeft, inorder, inLeft, pos - 1);
        res->right = helper(preorder, preLeft + pos - inLeft + 1, preRight, inorder, pos + 1, inRight);
        
        return res;
    }
};
