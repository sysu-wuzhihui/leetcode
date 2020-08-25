//剑指 Offer 32 - III. 从上到下打印二叉树 III
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
            if (r)	//偶数层反转 
                reverse(v.begin(), v.end());
            ret.push_back(v);
            r = !r;
        }

        return ret;
    }
};

//巧用deque，避免偶数层数组reverse操作
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
            if (leftToRight)	//从左到右遍历 
                while (n--)
                {
                    TreeNode* cur = dq.front();
                    dq.pop_front();
                    v.push_back(cur->val);
                    //先加入左子节点，再加入右子节点。保证连续 
                    if (cur->left)
                        dq.push_back(cur->left);
                    if (cur->right)
                        dq.push_back(cur->right);
                }
            else	//从右到左遍历 
                while (n--)
                {
                    TreeNode* cur = dq.back();
                    dq.pop_back();
                    v.push_back(cur->val);
                    //先加入右子节点，再加入左子节点，保证连续 
                    if (cur->right)
                        dq.push_front(cur->right);
                    if (cur->left)
                        dq.push_front(cur->left);
                }
            ret.push_back(v);
            leftToRight = !leftToRight;	//换一个方向 
        }
        return ret;
    }
};
