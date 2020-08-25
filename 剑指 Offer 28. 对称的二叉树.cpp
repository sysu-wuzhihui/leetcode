//剑指 Offer 28. 对称的二叉树
//递归 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* t1, TreeNode* t2)
    {
        if (!t1 && !t2)
            return true;
        if (!t1 || !t2 || t1->val != t2->val)
            return false;
        return helper(t1->left, t2->right) && helper(t1->right, t2->left);
    }
};

//层序遍历，连续两个节点值相等。 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();
            if (!node1 && !node2)
                continue;
            if (!node1 || !node2 || node1->val != node2->val)
                return false;
            //注意这里的入队顺序 
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }

        return true;
    }
}; 
