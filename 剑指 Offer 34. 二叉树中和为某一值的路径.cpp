//��ָ Offer 34. �������к�Ϊĳһֵ��·��
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return {};
        vector<vector<int>> res;
        vector<int> path;
        helper(res, root, sum, path);
        return res;
    }

    void helper(vector<vector<int>>& res, TreeNode* root, int sum, vector<int> path)
    {
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum)
            res.push_back(path);
        if (root->left)
            helper(res, root->left, sum - root->val, path);
        if (root->right)    
            helper(res, root->right, sum - root->val, path);
    }
}; 

//�������Ľ���path�����ô��ݣ����ݷ�
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return {};
        vector<vector<int>> res;
        vector<int> path;
        helper(res, root, sum, path);
        return res;
    }

    void helper(vector<vector<int>>& res, TreeNode* root, int sum, vector<int>& path)
    {
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum)
            res.push_back(path);
        if (root->left)
            helper(res, root->left, sum - root->val, path);
        if (root->right)    
            helper(res, root->right, sum - root->val, path);
        
        path.pop_back();
    }
}; 
