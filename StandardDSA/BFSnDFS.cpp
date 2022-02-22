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

void BFS(vector<vector<int>>& graph,map<int,bool> visited, int node){
    visited[node]=true;
    queue<int> q;
    q.push(node);
    int m;

    while(!q.empty()) {
        m=q.front();
        cout<<m<<" ";
        q.pop();
        vector<int> neighboursList= graph[m];
        for(int neighbour: neighboursList){
            if(!visited[neighbour]) {
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
}

void DFS(vector<vector<int>>& graph, map<int,bool>& visited, int node){
    cout<<node<<" ";
    visited[node]=true;

    vector<int> neighboursList=graph[node];
    for(int neighbour:neighboursList){
        if(!visited[neighbour]){
            DFS(graph,visited,neighbour);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph={
        {2,4},
        {},
        {5,7},
        {1},
        {1,3,4},
        {1,6},
        {1,5,6},
        {4,6}
    };

    cout<<"BFS:";
    map<int,bool> visited;
    BFS(graph,visited,0);

    cout<<"\nDFS:";
    //in the BFS method, we are not receiving the visited map as a reference,hence we don't need to clear the visited map.
    //visited.clear(); 
    DFS(graph,visited,0);
    cout<<"\n";
    return 0;
}
