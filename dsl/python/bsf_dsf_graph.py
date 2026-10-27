
from collections import deque

n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

adj_list = [[] for _ in range(n)]
adj_matrix = [[0] * n for _ in range(n)]

print("Enter edges (u v):")

for _ in range(e):
    u, v = map(int, input().split())

    adj_list[u].append(v)
    adj_list[v].append(u)

    adj_matrix[u][v] = 1
    adj_matrix[v][u] = 1

def bfs(start):
    visited = [False] * n
    queue = deque([start])
    visited[start] = True

    print("BFS Traversal:", end=" ")

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbour in adj_list[node]:
            if not visited[neighbour]:
                visited[neighbour] = True
                queue.append(neighbour)

    print()

def dfs(start):
    visited = [False] * n

    def visit(node):
        visited[node] = True
        print(node, end=" ")

        for neighbour in range(n):
            if adj_matrix[node][neighbour] == 1 and not visited[neighbour]:
                visit(neighbour)

    print("DFS Traversal:", end=" ")
    visit(start)
    print()

start = int(input("Enter starting vertex: "))

if 0 <= start < n:
    bfs(start)
    dfs(start)
else:
    print("Invalid starting vertex!")
