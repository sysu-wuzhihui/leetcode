//��ָ Offer 32 - II. ���ϵ��´�ӡ������ II
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;
            while (n--)
            {
                TreeNode* tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            ret.push_back(v);
        }

        return ret;
    }
};
