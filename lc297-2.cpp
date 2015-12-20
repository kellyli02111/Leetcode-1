class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(root == NULL) return "[]";
        res = res + "[";
        queue<TreeNode*> q;
        q.push(root);
        res = res + to_string(root->val) + ",";
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left == NULL){
                res = res + "null,";
            }
            else{
                q.push(cur->left);
                res = res + to_string(cur->left->val) + ",";
            }
            if(cur->right == NULL){
                res = res + "null,";
            }
            else{
                q.push(cur->right);
                res = res + to_string(cur->right->val) + ",";
            }
        }
        res = res.substr(0, res.size() - 0) + "]";
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q1;
        if(data == "[]") return NULL;
        int begin = 1;
        int length = 1;
        while(data[begin + length] != ','){
            length++;
        }
        string segment = data.substr(begin, length);
        begin = begin + length + 1;
        int val = stoi(segment);
        TreeNode* root = new TreeNode(val);
        q1.push(root);
        int size = data.size();
        TreeNode* cur;
        bool flag = true;
        while(begin != size - 1){
            if(flag == true){
                cur = q1.front();
                q1.pop();
            }
            int length = 1;
            while(data[begin + length] != ','){
                length++;
            }
            segment = data.substr(begin, length);
            begin = begin + length + 1;
            if(segment != "null"){
                int val = stoi(segment);
                TreeNode* newNode = new TreeNode(val);
                q1.push(newNode);
                if(flag == true){
                    cur->left = newNode;
                }
                else{
                    cur->right = newNode;
                }
            }
            flag = !flag;
        }
        return root;
    }
};
