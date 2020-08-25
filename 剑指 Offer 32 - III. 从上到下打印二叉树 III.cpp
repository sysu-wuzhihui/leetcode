//��ָ Offer 32 - III. ���ϵ��´�ӡ������ III
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ret;
        bool r = false;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;
            while (n--)
            {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if (r)	//ż���㷴ת 
                reverse(v.begin(), v.end());
            ret.push_back(v);
            r = !r;
        }

        return ret;
    }
};

//����deque������ż��������reverse����
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> ret;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool leftToRight = true;
        while (!dq.empty())
        {
            vector<int> v;
            int n = dq.size();
            if (leftToRight)	//�����ұ��� 
                while (n--)
                {
                    TreeNode* cur = dq.front();
                    dq.pop_front();
                    v.push_back(cur->val);
                    //�ȼ������ӽڵ㣬�ټ������ӽڵ㡣��֤���� 
                    if (cur->left)
                        dq.push_back(cur->left);
                    if (cur->right)
                        dq.push_back(cur->right);
                }
            else	//���ҵ������ 
                while (n--)
                {
                    TreeNode* cur = dq.back();
                    dq.pop_back();
                    v.push_back(cur->val);
                    //�ȼ������ӽڵ㣬�ټ������ӽڵ㣬��֤���� 
                    if (cur->right)
                        dq.push_front(cur->right);
                    if (cur->left)
                        dq.push_front(cur->left);
                }
            ret.push_back(v);
            leftToRight = !leftToRight;	//��һ������ 
        }
        return ret;
    }
};
