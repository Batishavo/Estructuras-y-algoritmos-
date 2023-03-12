#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> topo_order;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    topo_order.push_back(u);
}

void topological_sort() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(topo_order.begin(), topo_order.end());
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topological_sort();
    for (int u : topo_order) {
        cout << u << " ";
    }
    cout << endl;
    return 0;
}
