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

bool DFS(vector<vector<int>> graph, int visited[],int dfsVisited[], int node){
    visited[node]=1;
    dfsVisited[node]=1;
    
    vector<int> neighboursList=graph[node];

    // cout<<node<<" ";
    // cout<<"visited array: ";
    // for(int i=0;i<graph.size();i++) cout<<visited[i]<<" ";
    // cout<<"neighboursList: ";
    // for(auto it=neighboursList.begin();it!=neighboursList.end();it++) cout<<*it<<" ";
    // cout<<"dfsVisited: ";
    // for(int i=0;i<graph.size();i++) cout<<dfsVisited[i]<<" ";
    // cout<<"\n";
    
    for(int neighbour:neighboursList){
        if(!visited[neighbour]){
            if (DFS(graph,visited,dfsVisited,neighbour)) return true;
            dfsVisited[neighbour]=0;
        }
        else if(dfsVisited[neighbour]) return true;
    }
    dfsVisited[node]=0;
    return false;
}

bool isCyclic(int V, vector<vector<int>> graph) {
    int visited[V]={0},dfsVisited[V]={0};
    for(int i=0;i<V;i++){
        if(!visited[i] && DFS(graph,visited,dfsVisited,i)) return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    // vector<vector<int>> graph={
    //     {2,4},
    //     {},
    //     {5,7},
    //     {1},
    //     {1,3,4},
    //     {1,6},
    //     {},
    //     {4,6}
    // };
    vector<vector<int>> graph={
        {1,3},
        {0},
        {},
        {1,2}
    };
    cout<<(isCyclic(graph.size(),graph)?"Cycle detected":"No Cycle Detected");
    return 0;
}