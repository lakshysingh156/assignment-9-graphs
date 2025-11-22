//Lakshay Singh
//1024030975
//2C71
//Assignment 9 Krushal

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int v, vector<int> &parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) { return a.w < b.w; });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int total = 0;

    for (auto &e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cout << e.u << " " << e.v << " " << e.w << "\n";
            total += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << total;
    return 0;
}
