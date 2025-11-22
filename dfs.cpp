//Lakshay Singh 
//1024030975
//2C71
//Assignment 9 DFS

#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj, vis);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    vector<int> vis(n, 0);
    dfs(start, adj, vis);

    return 0;
}
