class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        res = res + "[";
        int depth = maxDepth(root);
        queue<TreeNode*> q;
        q.push(root);
        int lvlSize = 1;
        int nextLvlSize;
        for(int i = 0; i < depth; i++){
            int nextLvlSize = lvlSize * 2;
            for(int j = 0; j < lvlSize; j++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur == NULL){
                    nextLvlSize = nextLvlSize - 2;
                    res = res + "null,";
                }
                else{
                    q.push(cur->left);
                    q.push(cur->right);
                    res = res + to_string(cur->val) + ",";
                }
            }
            lvlSize = nextLvlSize;
        }
        res = res.substr(0, res.size() - 0) + "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
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
        int lvlSize = q1.size();
        int size = data.size();
        while(begin != size - 1){
            for(int i = 0; i < lvlSize; i++){
                if(begin == size - 1) break;
                TreeNode* cur = q1.front();
                q1.pop();
                int length = 1;
                while(data[begin + length] != ','){
                    length++;
                }
                string segment = data.substr(begin, length);
                begin = begin + length + 1;
                if(segment != "null"){
                    int val = stoi(segment);
                    TreeNode* newNode = new TreeNode(val);
                    q1.push(newNode);
                    cur->left = newNode;
                }
                if(begin == size - 1) break;
                length = 1;
                while(data[begin + length] != ','){
                    length++;
                }
                segment = data.substr(begin, length);
                begin = begin + length + 1;
                if(segment != "null"){
                    int val = stoi(segment);
                    TreeNode* newNode = new TreeNode(val);
                    q1.push(newNode);
                    cur->right = newNode;
                }
           }
           lvlSize = lvlSize * 2;
        }
        return root;
    }
    
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
