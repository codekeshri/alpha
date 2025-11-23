#include<iostream>
#include<vector>
#include<list> // doubly linked list
#include <stack>
#include <queue>
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

    void helper(int src, vector<bool>&vis){
        vis[src]=true;
        cout << src << " ";

        for(int v: l[src]){
            if(!vis[v])helper(v, vis);
        }
    }

    void dfs(int src){
        vector<bool>vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                helper(i, vis);
                cout << endl;
            }
        }
    }
};


int main(){
    Graph graph(10, true);
    graph.addEdge(0, 2);
    graph.addEdge(2, 5);
    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 9);
    graph.addEdge(4, 3);
    graph.addEdge(3, 8);
    graph.addEdge(3, 7);

    graph.dfs(0);


    return 0;
}