//剑指 Offer 32 - II. 从上到下打印二叉树 II
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
