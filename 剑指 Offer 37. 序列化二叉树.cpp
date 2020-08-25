//剑指 Offer 37. 序列化二叉树
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return string();
        stringstream res;
        queue<TreeNode*> Q;
        Q.push(root);

        //序列化即层次遍历
        while (!Q.empty())
        {
            TreeNode* tmp = Q.front();
            Q.pop();
            if (tmp)
            {
                res <<  to_string(tmp->val) << ' ';
                Q.push(tmp->left);  //不管子树是否为空，都要记录
                Q.push(tmp->right);
            }
            else
                res << "null ";
        }

        return res.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        stringstream ss(data);
        vector<TreeNode*> node;
        string tmp;
        while (ss >> tmp)
        {
            if (tmp != "null")
                node.push_back(new TreeNode(stoi(tmp)));
            else
                node.push_back(NULL);
        }

        //i指向父节点，j指向i的左子节点
        for (int i = 0, j = 1; j < node.size() - 1; ++i)
        {
            if (!node[i])
                continue;
            node[i]->left =  node[j++];
            node[i]->right = node[j++];
        }

        return node[0];
    }
};

