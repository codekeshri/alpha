#include<bits/stdc++.h>
using namespace std;

class Node{
  public: 
    int val;
    Node* next;

    Node(int val){
      this->val = val;
      this->next = nullptr;
    }
};

class Queue{
  public:
  Node *head, *tail;
  Queue(){
    head = tail = nullptr;
  }

  void push(int val){
    Node* temp = new Node(val);
    if(head == nullptr){
      head=tail=temp;
    }else{
      tail->next = temp;
      tail = temp;
    }

  }

  void pop(){
    if(head)head = head->next;
  }
  
  int front(){
    return head ? head->val: -1;
  }
  
  bool empty(){
    return head ? false : true;
  }
};

int main(){
  Queue q;
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q.pop();
  cout << q.empty() << "\n";
  while(!q.empty()){
    cout << q.front() << " " ;
    q.pop();
  }
  return 0; 
}