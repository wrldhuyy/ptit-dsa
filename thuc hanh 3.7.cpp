#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
vector<int> adj[MAXN];
int tin[MAXN], low[MAXN];
bool visited[MAXN];
bool isArt[MAXN];
int timer;

int n, m;
int bridges = 0;

void dfs(int u, int parent) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) bridges++;
            if (low[v] >= tin[u] && parent != -1)
                isArt[u] = true;

            children++;
        }
    }
    if (parent == -1 && children > 1)
        isArt[u] = true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i, -1);
    }

    int articulation = 0;
    for (int i = 1; i <= n; i++) {
        if (isArt[i]) articulation++;
    }

    cout << articulation << " " << bridges;
}