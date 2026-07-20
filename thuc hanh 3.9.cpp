#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[105];
bool visited[105];

void dfs(int u, int removed) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (v == removed) continue;
        if (!visited[v]) dfs(v, removed);
    }
}

int countComponents(int removed) {
    memset(visited, false, sizeof(visited));
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        if (i == removed) continue;
        if (!visited[i]) {
            dfs(i, removed);
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        // clear graph
        for (int i = 1; i <= N; i++) adj[i].clear();

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int bestNode = 0;
        int maxComp = 1;

        for (int i = 1; i <= N; i++) {
            int comp = countComponents(i);

            if (comp > maxComp) {
                maxComp = comp;
                bestNode = i;
            }
        }

        cout << bestNode << '\n';
    }

    return 0;
}