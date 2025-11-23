#include<iostream>
#include<vector>
#include<list> // doubly linked list
#include <stack>
using namespace std;

class Graph {
    int V;
    list<int>*l;
    bool isUndir;

public: 
    Graph(int x, bool isUndir = true){
        V = x;
        l = new list<int>[x];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        if(isUndir)l[v].push_back(u);
    }

    void topoHelper(int src, vector<bool>&vis, stack<int>&s){   // O(V+E)
        vis[src]=true;
        list<int>neighbors = l[src];
        for(int v: neighbors)if(!vis[v])topoHelper(v, vis, s);
        s.push(src);
    }
    
    void topoSort(){
        vector<bool> vis(V, false);
        stack<int>s;
        for(int i=0; i<V; i++)if(!vis[i])topoHelper(i, vis, s);
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        
    }
};


int main(){
    Graph graph(6, false);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.addEdge(4, 0);
    graph.addEdge(4, 1);

    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topoSort();

    return 0;
}