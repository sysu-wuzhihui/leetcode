//��ָ Offer 27. �������ľ���
//�����ǽ���ÿ���ڵ�������ӽڵ� 
//�ݹ� 
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
            return root;
        TreeNode *left = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(left);

        return root;
    }
};

//����ջ
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
            return root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();
            TreeNode *left = cur->left, *right = cur->right;
            if (left)
                st.push(left);
            if (right)
                st.push(right);
            cur->left = right;
            cur->right = left;
        }

        return root;
    }
};

//������������������ӽڵ�
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            TreeNode *left = cur->left, *right = cur->right;
            if (left)
                q.push(left);
            if (right)
                q.push(right);
            cur->left = right;
            cur->right = left;
        }

        return root;
    }
}; 
