#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20005;
vector<int> adj[MAXN];
bool visited[MAXN];
int n, m;

void dfs(int u, int removed) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (v == removed) continue;
        if (!visited[v]) dfs(v, removed);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int removed = 1; removed <= n; removed++) {
        memset(visited, false, sizeof(visited));

        int components = 0;

        for (int i = 1; i <= n; i++) {
            if (i == removed) continue;

            if (!visited[i]) {
                dfs(i, removed);
                components++;
            }
        }

        cout << components << '\n';
    }

    return 0;
}