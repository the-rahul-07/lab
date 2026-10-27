
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> adjList;
vector<vector<int>> adjMatrix;

void bfs(int start) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : adjList[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    cout << endl;
}

void dfs(int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            dfs(i, visited);
        }
    }
}

int main() {
    int e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    adjList.resize(n);
    adjMatrix.assign(n, vector<int>(n, 0));

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= n) {
        cout << "Invalid starting vertex!" << endl;
        return 0;
    }

    bfs(start);

    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    dfs(start, visited);
    cout << endl;

    return 0;
}
