#include <bits/stdc++.h>
using namespace std;

class Heap {
  vector<int>v;    // max heap
public: 
  void push(int val){
    v.push_back(val);
    // now fix the tree
    int x = v.size()-1;    //index of child
    int p = (x-1)/2 ;      // index of parent
    while(p >= 0 && v[p] < v[x]){
      cout << x << " " << p << endl;
      swap(v[x], v[p]);
      x = p; 
      p = (x-1)/2;
    } 
  }
  void pop(int val){

  }

  int top(){
    return v[0];
  }

  bool empty(){
    return v.size() == 0;
  }

};

int main(){
  Heap heap;
  heap.push(50);
  heap.push(100);
  heap.push(150);
  heap.push(250);
  heap.push(350);

  cout << heap.top();
}