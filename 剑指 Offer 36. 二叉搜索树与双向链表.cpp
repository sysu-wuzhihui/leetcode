//剑指 Offer 36. 二叉搜索树与双向链表

//递归 
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return root;
        Node *left = treeToDoublyList(root->left), *right = treeToDoublyList(root->right);
        Node *ret = left, *leftEnd = left, *rightEnd = right;
        if (left && right)
        {
            while (leftEnd && leftEnd->right != left)
                leftEnd = leftEnd->right;
            leftEnd->right = root;
            root->left = leftEnd;
            while (rightEnd && rightEnd->right != right)
                rightEnd = rightEnd->right;
            root->right = right;
            right->left = root;
            left->left = rightEnd;
            rightEnd->right = left;
            ret = left;
        }
        else if (left)
        {
            while (leftEnd && leftEnd->right != left)
                leftEnd = leftEnd->right;
            leftEnd->right = root;
            root->left = leftEnd;
            root->right = left;
            left->left = root;
            ret = left;            
        }
        else if (right)
        {
            while (rightEnd && rightEnd->right != right)
                rightEnd = rightEnd->right;
            root->right = right;
            right->left = root;
            root->left = rightEnd;
            rightEnd->right = root;
            ret = root;            
        }
        else
        {
            root->left = root;
            root->right = root;
            ret = root;
        }

        return ret;
    }
};

//先中序遍历，再处理连接 
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return root;
        vector<Node*> v;
       inorder(root, v);
       for (int i = 0; i < v.size(); ++i)
       {
           v[i]->right = v[(i + 1) % v.size()];
           v[i]->left = v[(i - 1 + v.size()) % v.size()];
       }

       return v[0];
    }

    void inorder(Node* root, vector<Node*>& v)
    {
        if (!root)
            return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
}; 

//直接中序遍历得出结果
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return root;
        Node *pre = NULL, *head = NULL;
        inorder(root, pre, head);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void inorder(Node* root, Node*& pre, Node*& head)
    {
        if (!root)
            return;
        inorder(root->left, pre, head);
        if (!pre)
            head = root;
        else
        {
            pre->right = root;
            root->left = pre;
        }
        pre = root;
        inorder(root->right, pre, head);
    }
}; 
