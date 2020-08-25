//剑指 Offer 35. 复杂链表的复制

//使用hash表 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(-1);
        Node *copyCur = dummy, *cur = head;
        unordered_map<Node*, int> um;
        vector<Node*> v;
        int i = 0;
        while (cur)
        {
            um.insert(pair<Node*, int>(cur, i));
            Node *newNode = new Node(cur->val);
            v.push_back(newNode);
            copyCur->next = newNode;

            cur = cur->next;
            copyCur = copyCur->next;
            ++i;

        }

        cur = head;
        copyCur = dummy->next;
        while (cur)
        {
            if (!cur->random)
                copyCur->random = NULL;
            else
            {
                int index = um[cur->random];
                copyCur->random = v[index];
            }
            
            cur = cur->next;
            copyCur = copyCur->next;
        }

        return dummy->next;
    }
};

//上面代码优化版.利用hash表，保存相对位置 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        unordered_map<Node*, Node*> um;
        Node* cur = head;
        while (cur)
        {
            um.insert({cur, new Node(cur->val)});
            cur = cur->next;
        }

        cur = head;
        while (cur)
        {
            um[cur]->next = um[cur->next];
            um[cur]->random = um[cur->random];
            cur = cur->next;
        }

        return um[head];
    }
}; 
