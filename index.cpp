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

  void levelorder(Node* root){
    
  }


int main(){
  vector<int>v = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root =  buildTree(v);
  preorder(root);
  cout << endl;
  inorder(root);
  cout<<endl;
  postorder(root);


}