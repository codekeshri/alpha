#include<iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int>v;
    public:
        void push(int val){
            v.push_back(val);
        }

        int top(){
            if(isEmpty())return -1;
            return v[v.size()-1];
        }

        void pop(){
            if(isEmpty())return;
            v.pop_back();
        }
        void print(){
            if(isEmpty())return;
            for(auto i: v)cout << i << " ";
        }

        bool isEmpty(){
            return !v.size();
        }
};

int main(){
    Stack s;
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(7);

    s.print();

    cout << s.isEmpty() << "\n";

    while(!s.isEmpty()){
        cout << s.top() << " ";
        s.pop();
    } 


    return 0;
}

