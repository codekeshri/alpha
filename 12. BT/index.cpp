#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int val;
  Node *left, *right;

  Node(int val){
    this->val = val;
    this->left = this->right = NULL;
  }
};

static int idx = -1;
Node* buildTree(vector<int>v){
  idx++;
  if(v[idx]==-1)return NULL;

  Node* temp = new Node(v[idx]);
  temp->left = buildTree(v); 
  temp->right = buildTree(v); 
  return temp;
}

// DFS
void preorder(Node* root){
  if(root == NULL)return;
  cout << root->val <<" ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node* root){
  if(!root)return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

void postorder(Node* root){
  if(!root)return;
  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
}

// BFS - iterative
void levelorder(Node* root){
  if(root == NULL)return;
  queue<Node*>q;
    q.push(root);
    while(!q.empty()){
      cout << q.front()->val << " ";
      if(q.front()->left)q.push(q.front()->left);
      if(q.front()->right)q.push(q.front()->right);
      q.pop();
  }
}

void levelorder1(Node* root){
  if(root == NULL)return;
  queue<Node*>q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    q.pop();
    if(q.front() == NULL){
      if(q.empty())break;
      cout << endl;
      q.push(NULL);
    }else{
      cout << q.front()->val << " ";
      if(q.front()->left)q.push(q.front()->left);
      if(q.front()->right)q.push(q.front()->right);
    }
  }
}

int height(Node* root){
  if(!root)return 0;
  return 1 + max(height(root->left), height(root->right));

}

int count(Node* root){
  if(!root)return 0;
  return 1 + count(root->left) + count(root->right);
}

int sum(Node* root){
  if(!root)return 0;
  return root->val + sum(root->left) + sum(root->right);
}

int maximum(Node* root){
  if(!root)return 0;
  return max(root->val, max(maximum(root->left), maximum(root->right)));
}

int diameter(Node* root){   //O(n^2)
  if(!root)return 0;

  int currDia = height(root->left) + height(root->right) + 1;
  int leftDia = diameter(root->left);
  int rightDia = diameter(root->right);
  return max(currDia, max(leftDia, rightDia));
}

pair<int, int> diameterOptimized(Node* root){  // O(n) - (dia, height)
  if(!root)return make_pair(0, 0);

  pair<int, int> leftInfo = diameterOptimized(root->left); //(LD, LH)
  pair<int, int> rightInfo = diameterOptimized(root->right); // (RD, RH)

  int currDia = leftInfo.second + rightInfo.second + 1;
  int finalDia = max(currDia, max(leftInfo.first, rightInfo.first));
  int finalHt = 1 + max(leftInfo.second, rightInfo.second);

  return make_pair(finalDia, finalHt); 
}

void topView(Node* root){
  queue<pair<Node*, int>>q;  // (node, HD)
  map<int, int>m;    // (HD, node->val)

  q.push(make_pair(root, 0));
  while(!q.empty()){
    pair<Node*, int> curr = q.front();
    q.pop();

    Node* currNode = curr.first;
    int currHD = curr.second;

    if(m.count(currHD)==0)m[currHD] = currNode->val;
    
    if(currNode->left)q.push(make_pair(currNode->left, currHD - 1));
    if(currNode->right)q.push(make_pair(currNode->right, currHD + 1));
  }

  for(auto it: m)cout << it.second << " ";
}



bool rootToNodePath(Node* root, int n, vector<int>& path){
  if(!root)return false;
  path.push_back(root->val);

  if(root->val == n)return true;
  bool p1 = rootToNodePath(root->left, n, path);
  bool p2 = rootToNodePath(root->right, n, path);

  if(p1 || p2) return true;
  path.pop_back();
  return false;

}


int LCA(Node* root, int n1, int n2){ // O(n)- tc and O(n) - sc as we are uing one vector 
  vector<int>path1, path2;
  rootToNodePath(root, n1, path1); //O(n) -tc
  rootToNodePath(root, n2, path2); // O(n) - tc

  int lca = -1;
  for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++){
    if(path1[i] != path2[j])return lca;
    lca = path1[i];
  }
  return lca;
}




Node* LCA2(Node* root, int n1, int n2){
  if(!root)return NULL;
  if(root->val == n1 || root->val == n2)return root;

  Node* leftLCA = LCA2(root->left, n1, n2);
  Node* rightLCA = LCA2(root->right, n1, n2);

  if(leftLCA && rightLCA)return root;
  return !leftLCA ? rightLCA : leftLCA ;
}




int main(){
  vector<int>v = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root =  buildTree(v);

  cout << LCA(root, 2, 4);

  return 0;
}