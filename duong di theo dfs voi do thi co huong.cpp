#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E, s, t;
        cin >> V >> E >> s >> t;
        for (int i = 1; i <= V; i++) {
            adj[i].clear();
            visited[i] = false;
            parent[i] = -1;
        }
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for (int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        dfs(s);

        if (!visited[t]) {
            cout << -1 << endl;
            continue;
        }

        vector<int> path;
        int cur = t;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }

        reverse(path.begin(), path.end());

        for (int x : path) cout << x << " ";
        cout << endl;
    }
}