#include <bits/stdc++.h>
using namespace std;

int parent[100005], sz[100005];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[v] = u;
        sz[u] += sz[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        vector<pair<int,int>> edges;

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            unite(u, v);
        }
        map<int, int> edgeCount;

        for (auto e : edges) {
            int root = find(e.first);
            edgeCount[root]++;
        }

        bool ok = true;

        for (int i = 1; i <= N; i++) {
            if (find(i) == i) {
                int k = sz[i];
                int e = edgeCount[i];
                if (e != k * (k - 1) / 2) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}