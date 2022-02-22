#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<iterator>
#include<climits>
#include<cmath>
#include<utility>
#include<valarray>
#include<numeric>
#include<queue>
#include<stack>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define NIL -1

typedef long long int ll;
typedef unsigned long long int ull;

using namespace __gnu_pbds;
using namespace std;

typedef 
    tree<int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
orderedList;

// GFG Practice.
vector<int> BFSgfg(vector<vector<int>>& graph,map<int,bool>& visited, int node){
    visited[node]=true;
    queue<int> q;
    q.push(node);
    int m;
    vector<int> ans;

    while(!q.empty()) {
        m=q.front();
        //cout<<m<<" ";
        ans.push_back(m);
        q.pop();
        vector<int> neighboursList= graph[m];
        for(int neighbour: neighboursList){
            if(!visited[neighbour]) {
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    return ans;
}

// Function to return Breadth First Traversal of given graph. GFG Practice.
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    map<int,bool> visited;
    vector<vector<int>> graph;
    for(int i=0;i<V;i++){
        graph.push_back(adj[i]);
    }
    vector<int> ans;
    for(int i=0;i<V;i++){
        if(!visited[i] && !graph[i].empty()){
            vector<int> currentNodeBFS=BFSgfg(graph,visited,i);
            ans.insert(ans.end(),currentNodeBFS.begin(),currentNodeBFS.end());
        }
    }
    return ans;
}

void DFS(vector<vector<int>>& graph, map<int,bool>& visited, int node,vector<int> & ans){
    //cout<<node<<" ";
    ans.push_back(node);
    visited[node]=true;

    vector<int> neighboursList=graph[node];
    for(int neighbour:neighboursList){
        if(!visited[neighbour]){
            DFS(graph,visited,neighbour,ans);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<vector<int>> graph;
    for(int i=0;i<V;i++){
        graph.push_back(adj[i]);
    }
    map<int,bool> visited;
    vector<int> ans;
    for(int i=0;i<V;i++){
        if(!visited[i] && !graph[i].empty()) {
            DFS(graph,visited,i,ans);
            return ans;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
