graph={
    0:[2,4],
    1:[],
    2:[5,7],
    3:[1],
    4:[1,3,4],
    5:[1,6],
    6:[1,5,6],
    7:[4,6]
}
def BFS(graph,visited,node):
    visited[node]=True
    queue=[node]
    
    while queue:
        m=queue.pop(0)
        print(m,end=" ")
        neighboursList=graph[m]
        for neighbour in neighboursList:
            if neighbour not in visited:
                visited[neighbour]=True
                queue.append(neighbour)

def DFS(graph,visited,node):
    print(node,end=" ")
    visited[node]=True

    m=graph[node]
    for neighbour in m:
        if neighbour not in visited:
            DFS(graph,visited,neighbour)

print('BFS:',end=" ")
BFS(graph,{},0)
print('\nDFS:',end=" ")
DFS(graph,{},0)
print()