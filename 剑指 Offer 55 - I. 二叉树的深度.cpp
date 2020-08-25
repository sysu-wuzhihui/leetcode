//��ָ Offer 55 - I. �����������
//�ݹ飬�������Ǻ������ 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

//�������
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            depth += 1;
            int s = q.size();
            while (s-- > 0)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
        }

        return depth;
    }
}; 
