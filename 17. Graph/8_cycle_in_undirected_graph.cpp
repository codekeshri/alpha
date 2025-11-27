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

    void dfsHelper(int src, vector<bool>&vis, int parent, bool &isCycle){
        vis[src]=true;
        cout << src << " ";
        for(int v: l[src]){
            if(!vis[v])dfsHelper(v, vis, src, isCycle);
            else if (v==parent)isCycle = true;
        }

    }

    void dfs(){
        vector<bool>vis(V, false);
        bool isCycle = false;
        for(int i=0; i<V; i++){
            if(!vis[i])dfsHelper(i, vis, -1, isCycle);
        }
        cout << endl << isCycle ;
    }
    
};


int main(){
    Graph graph(6, true);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);

    graph.addEdge(0, 3);
    graph.addEdge(3, 4);


    graph.dfs();


    return 0;
}