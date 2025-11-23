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

    void bfs(int src){ // O(V+E)
        queue<int>q;
        vector<bool>vis(V, false);
        q.push(src);

        while(q.size()>0){
            int front = q.front();
            q.pop();
            cout << front << " ";
            list<int>neighbors = l[front];
            for(int v: neighbors){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }

        }
        cout << endl;
        
    }

    
};


int main(){
    Graph graph(6, false);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);

    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    graph.addEdge(4, 5);

    graph.addEdge(5, 6);

    graph.bfs(0);


    return 0;
}