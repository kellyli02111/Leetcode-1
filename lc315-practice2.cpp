#include <iostream>
#include <queue>
#include <string>
#include <math.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int depth;
    TreeNode(int value){
        val = value;
        left = NULL;
        right = NULL;
        depth = 1;
    }
};
// To execute C++, please define "int main()"
    string serialize(TreeNode* root);
    TreeNode* deserialize(string data);
    TreeNode* buildBST(vector<int>& nums);
    TreeNode* buildAVL(vector<int>& nums);
    void rotateRR(TreeNode* root, TreeNode* pre);
    void rotateRR_violate(TreeNode* root, TreeNode* pre);
    void rotateRR_noviolate(TreeNode* root, TreeNode* pre);
    void rotateLL(TreeNode* root, TreeNode* pre);
    void rotateLL_violate(TreeNode* root, TreeNode* pre);
    void rotateLL_noviolate(TreeNode* root, TreeNode* pre);
    void rotateRL_violate(TreeNode* root, TreeNode* pre);
    void rotateLR_violate(TreeNode* root, TreeNode* pre);
    int maxDepth(TreeNode* root);
    string printTree(TreeNode* root);
    bool isBalanced(TreeNode* root);
    int main() {
        vector<int> input;
        for(int i = 0; i < 1000; i++){
            input.push_back(i);
        }
        for(int i = 0; i < 1000; i++){
            srand (time(NULL));
            int swapInd = rand() % 1000;
            swap(input[i], input[swapInd]);
        }
        TreeNode* root = buildBST(input);
        string output = serialize(root);
        string print;
        //print = printTree(root);
        TreeNode* avlRoot = buildAVL(input);
        output = serialize(avlRoot);
        print = printTree(avlRoot);
        cout<<"BSTbalanced? "<<isBalanced(root)<<endl;
        cout<<"AVLbalanced? "<<isBalanced(avlRoot)<<endl;
    }

  TreeNode* buildBST(vector<int>& nums){
    int n = nums.size();
    TreeNode* root = new TreeNode(nums[0]);
    for(int i = 1; i < n; i++){
      TreeNode* cur = root;
      while(true){
        if(cur->val > nums[i]){
          if(cur->left != NULL){
            cur = cur->left;
          }
          else{
            TreeNode* newNode = new TreeNode(nums[i]);
            cur->left = newNode;
            break;
          }
        }
        else{
          if(cur->right != NULL){
            cur = cur->right;
          }
          else{
            TreeNode* newNode = new TreeNode(nums[i]);
            cur->right = newNode;
            break;
          }
        }
      }
    }
    return root;
  }
  TreeNode* buildAVL(vector<int>& nums){
    int n = nums.size();
    TreeNode* dummy = new TreeNode(0);
    TreeNode* root = new TreeNode(nums[0]);
    dummy->left = root;
    for(int i = 1; i < n; i++){
      vector<TreeNode*> path;
      path.push_back(dummy);
      TreeNode* cur = dummy->left;
      while(true){
        path.push_back(cur);
        if(cur->val > nums[i]){
          if(cur->left != NULL){
            cur = cur->left;
          } else{
            TreeNode* newNode = new TreeNode(nums[i]);
            cur->left = newNode;
            break;
          }
        } else{
          if(cur->right != NULL){
            cur = cur->right;
          } else{
            TreeNode* newNode = new TreeNode(nums[i]);
            cur->right = newNode;
            break;
          }
        }
      }
      int pathSize = path.size();
      for(int j = 0; j < pathSize; j++){
        path[j]->depth = max(path[j]->depth, pathSize + 1 - j);
      }
      for(int j = pathSize - 1; j >= 1; j--){
        int leftDepth;
        int rightDepth;
        if(path[j]->left == NULL){
          leftDepth = 0;
        }
        else{
          leftDepth = path[j]->left->depth;
        }
        if(path[j]->right == NULL){
          rightDepth = 0;
        }
        else{
          rightDepth = path[j]->right->depth;
        }
        if(leftDepth - rightDepth > 1){
          TreeNode* temp = path[j]->left;
          if(maxDepth(temp->left) >= maxDepth(temp->right)){
            rotateLL_violate(path[j], path[j - 1]);
          } else {
            rotateLR_violate(path[j], path[j - 1]);
          }
        }
        if(rightDepth - leftDepth > 1){
          TreeNode* temp = path[j]->right;
          if(maxDepth(temp->right) >= maxDepth(temp->left)){
            rotateRR_violate(path[j], path[j - 1]);
          } else{
            rotateRL_violate(path[j], path[j - 1]);
          }
        }
      }
    }
    return dummy->left;
  }
  void rotateRR(TreeNode* root, TreeNode* pre){
    TreeNode* next = root->right;
    if(pre->left == root){
      pre->left = next;
    }
    else{
      pre->right = next;
    }
    root->right = next->left;
    next->left = root;
  }

  void rotateLL(TreeNode* root, TreeNode* pre){
    TreeNode* next = root->left;
    if(pre->left == root){
      pre->left = next;
    }
    else{
      pre->right = next;
    }
    root->left = next->right;
    next->right = root;
  }
  
  void rotateRR_violate(TreeNode* root, TreeNode* pre){
    root->depth = root->depth - 2;
    pre->depth = pre->depth - 1;
    rotateRR(root, pre);
  }

  void rotateRR_noviolate(TreeNode* root, TreeNode* pre){
    root->depth = root->depth - 1;
    root->right->depth = root->right->depth + 1;
    rotateRR(root, pre);
  }

  void rotateLL_violate(TreeNode* root, TreeNode* pre){
    root->depth = root->depth - 2;
    pre->depth = pre->depth - 1;
    rotateLL(root, pre);
  }

  void rotateLL_noviolate(TreeNode* root, TreeNode* pre){
    root->depth = root->depth - 1;
    root->left->depth = root->left->depth + 1;
    rotateLL(root, pre);
  }
  
  void rotateRL_violate(TreeNode* root, TreeNode* pre){
    if(root->right->right == NULL){
      if(root->right->depth >= 3){
        rotateLL_violate(root->right, root);
      }
      else{
        rotateLL_noviolate(root->right, root);
      }
    }
    else{
      if(root->right->depth - root->right->right->depth >= 3){
        rotateLL_violate(root->right, root);
      }
      else{
        rotateLL_noviolate(root->right, root);
      }
    }
    if(root->left == NULL){
      if(root->depth >= 3){
        rotateRR_violate(root, pre);
      }
      else{
        rotateRR_noviolate(root, pre);
      }
    }
    else{
      if(root->depth - root->left->depth >= 3){
        rotateRR_violate(root, pre);
      }
      else{
        rotateRR_noviolate(root, pre);
      }
    }
  }

  void rotateLR_violate(TreeNode* root, TreeNode* pre){
    if(root->left->left == NULL){
      if(root->left->depth >= 3){
        rotateRR_violate(root->left, root);
      }
      else{
        rotateRR_noviolate(root->left, root);
      }
    }
    else{
      if(root->left->depth - root->left->left->depth >= 3){
        rotateRR_violate(root->left, root);
      }
      else{
        rotateRR_noviolate(root->left, root);
      }
    }
    if(root->right == NULL){
      if(root->depth >= 3){
        rotateLL_violate(root, pre);
      }
      else{
        rotateLL_noviolate(root, pre);
      }
    }
    else{
      if(root->depth - root->right->depth >= 3){
        rotateLL_violate(root, pre);
      }
      else{
        rotateLL_noviolate(root, pre);
      }
    }
  }

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
      return res;
  }

      // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
      queue<TreeNode*> q1;
      if(data == "[]") return NULL;
      int begin = 1;
      int pos = data.find(',',begin);
      string segment = data.substr(begin, pos - begin);
      begin = pos + 1;
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
          pos = data.find(',',begin);
          segment = data.substr(begin, pos - begin);
          begin = pos + 1;
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
  string printTree(TreeNode* root) {
    string res = "";
    res = res + "[";
    int depth = maxDepth(root);
    queue<TreeNode*> q;
    q.push(root);
    int lvlSize = 1;
    int numSpace = pow(3,maxDepth(root));
    int nextLvlSize = 0;
    for(int i = 0; i < depth; i++){
        int nextLvlSize = lvlSize * 2;
        /*for(int k = 0; k < numSpace / 3; k++){
            cout<<" ";
        }*/
        for(int j = 0; j < lvlSize; j++){
            TreeNode* cur = q.front();
            q.pop();
            if(cur == NULL){
                q.push(NULL);
                q.push(NULL);
                res = res + "null,";
                cout<<"# ";
            }
            else{
                q.push(cur->left);
                q.push(cur->right);
                res = res + to_string(cur->val) + ",";
                cout<<cur->val<<" ";
            }
            /*for(int k = 0; k < numSpace; k++){
                cout<<" ";
            }*/
        }
        numSpace = numSpace / 3;
        lvlSize = nextLvlSize;
        cout<<endl;
    }
    res = res.substr(0, res.size() - 0) + "]";
    return res;
  }

  int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));

    }    
