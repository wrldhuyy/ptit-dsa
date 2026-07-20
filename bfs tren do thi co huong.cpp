#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int v : adj[x]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E, u;
        cin >> V >> E >> u;
        for (int i = 1; i <= V; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for (int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        bfs(u);
        cout << endl;
    }
}