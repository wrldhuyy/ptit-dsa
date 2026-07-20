#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
vector<int> res;

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();

        for (int i = 0; i < adj[v].size(); i++) {
            if (adj[v][i] == u) {
                adj[v].erase(adj[v].begin() + i);
                break;
            }
        }

        dfs(v);
    }
    res.push_back(u);
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(start);

    reverse(res.begin(), res.end());

    for (int x : res) cout << x << " ";
}