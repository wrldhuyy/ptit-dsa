#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];

int dfs(int u) {
    visited[u] = true;
    int cnt = 1; 

    for (int v : adj[u]) {
        if (!visited[v]) {
            cnt += dfs(v);
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                int size = dfs(i);
                ans = max(ans, size);
            }
        }

        cout << ans << "\n";
    }
}