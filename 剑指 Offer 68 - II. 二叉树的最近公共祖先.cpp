//��ָ Offer 68 - II. �������������������
//����������ҵ�p��q�ڵ㣬���ϴ��ݣ���ĳ�ڵ����ҽڵ㴫�������Ľڵ㶼��Ϊ�գ�˵���ýڵ�Ϊ������ڵ㣬���Ϸ��ؽ��������˵��������ڵ��������������������� 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;	//�����������һ�������ս���� 
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;	//���������һ�������ս�� 
		return left ? left : right; 
    }
}; 

