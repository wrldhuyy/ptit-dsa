#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> N >> M;
    adj.assign(N + 1, {});
    visited.assign(N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

    bool ok = false;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << i << endl;
            ok = true;
        }
    }

    if (!ok) cout << 0;

    return 0;
}