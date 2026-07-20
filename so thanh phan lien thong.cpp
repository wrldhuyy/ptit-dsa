#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}
void printPath(int s, int v) {
    if (!visited[v]) {
        cout << "No path\n";
        return;
    }

    vector<int> path;
    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }

    reverse(path.begin(), path.end());

    for (int x : path) cout << x << " ";
    cout << "\n";
}

int main() {

    int T; cin >> T;
    while (T--) {
        int N, M, s;
        cin >> N >> M >> s;

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

        bfs(s);

        for (int i = 1; i <= N; i++) {
            if (i != s) {
                printPath(s, i);
            }
        }
    }
}