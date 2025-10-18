#include<iostream>
#include <list>
using namespace std;

template<class T>
class Stack {
    list<T>ll;

    public:
        void push(T val){
            ll.push_front(val);
        }

        T top(){
            // if(isEmpty()) return 
            return ll.front();
        }

        void pop(){
            if(isEmpty())return;
            ll.pop_front();
        }
        void print(){
            if(isEmpty())return;
            for(auto &i: ll)cout << i << " ";
        }

        bool isEmpty(){
            return !ll.size();
        }
};

int main(){
    Stack<int> s;
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