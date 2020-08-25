//��ָ Offer 32 - I. ���ϵ��´�ӡ������
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
 
