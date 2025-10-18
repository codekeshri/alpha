#include<iostream>
#include <stack>
#include<vector>
using namespace std;

// This is recursive way of reversing a stack 
// Note that iterative way is more efficient. Its tc is O(n) just that it uses 2 more stacks.
void pushToBottom(stack<int>&st, int x){
    if(st.empty())st.push(x);
    else {
        int temp = st.top();
        st.pop();
        pushToBottom(st, x);
        st.push(temp);
    }

}

void reverse(stack<int> &st){
    if(!st.size())return;

    int temp = st.top();
    st.pop();
    reverse(st);
    pushToBottom(st, temp);

}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    pushToBottom(st, 11);
    reverse(st);
    while(st.size()){
        cout << st.top() << " ";
        st.pop();
    } 
    

    return 0;
}