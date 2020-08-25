//剑指 Offer 32 - I. 从上到下打印二叉树
//bfs
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            res.push_back(tmp->val);
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }

        return res;

    }
};
 
