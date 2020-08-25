//��ָ Offer 55 - II. ƽ�������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //�򵥵ݹ飬���Ӷ�Ϊo(nlogn) 
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

//�������ߵ�ʱ��ֱ���ж����Ƿ�ƽ�⣬ʵ�ּ�֦�����Ӷ�o(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        return height(root) != -1;  //ֱ���ڼ������ߵ�ʱ���ж��Ƿ�ƽ��
    }

    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        int l = height(root->left);
        if (l == -1)	//һ����⵽�������������������أ������ټ��������� 
            return -1;
        int r = height(root->right);
        if (r == -1)
            return -1;
        
        return abs(l - r) <= 1 ? 1 + max(l, r) : -1;
    }
}; 
