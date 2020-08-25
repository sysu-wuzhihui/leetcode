//��ָ Offer 37. ���л�������
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return string();
        stringstream res;
        queue<TreeNode*> Q;
        Q.push(root);

        //���л�����α���
        while (!Q.empty())
        {
            TreeNode* tmp = Q.front();
            Q.pop();
            if (tmp)
            {
                res <<  to_string(tmp->val) << ' ';
                Q.push(tmp->left);  //���������Ƿ�Ϊ�գ���Ҫ��¼
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

        //iָ�򸸽ڵ㣬jָ��i�����ӽڵ�
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

