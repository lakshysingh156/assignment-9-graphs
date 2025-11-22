//Lakshay Singh
//1024030975
//2C71
//Assignment 9 Prim's MST

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cin >> start;

    vector<int> vis(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, start});

    int total = 0;

    while (!pq.empty()) {
        pair<int,int> curr = pq.top();
        pq.pop();

        int w = curr.first;
        int u = curr.second;

        if (vis[u]) continue;
        vis[u] = 1;
        total += w;

        for (auto x : adj[u]) {
            pq.push({x.second, x.first});
        }
    }

    cout << total;
    return 0;
}
