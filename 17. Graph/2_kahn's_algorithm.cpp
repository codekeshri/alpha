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

    void calIndegree(vector<int>&indeg){
        for(int u=0; u<V; u++){
            list<int>neighbors = l[u];
            for(int v: neighbors){
                indeg[v]++;
            }
        }
    }

    void topoSort2(){   // start with a node having indegree 0 O(V+E)
        // Kahn's algo
        vector<int>indeg(V, 0);
        calIndegree(indeg);
        queue<int>q;

        for(int i=0; i<V; i++){
            if(indeg[i]==0)q.push(i);
            while(!q.empty()){
                int curr = q.front();
                q.pop();

                cout << curr << " ";
                list<int>neighbors = l[curr];
                for(int v: neighbors){
                    indeg[v]--;
                    if(indeg[v]==0)q.push(v);
                }
            }
        }

        cout << endl;


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

    graph.topoSort2();


    return 0;
}