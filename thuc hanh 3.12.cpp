#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, c;
};

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> color(n + 1);
        for (int i = 1; i <= n; i++) cin >> color[i];

        vector<vector<Edge>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
        }
        static bool visited[205][205][3];
        memset(visited, false, sizeof(visited));

        queue<tuple<int,int,int,int>> q;


        q.push({1, 2, 0, 0});
        visited[1][2][0] = true;

        int ans = -1;

        while (!q.empty()) {
            auto [u, v, t, dist] = q.front(); q.pop();

            if (u == v) {
                ans = dist;
                break;
            }

            int nt = (t + 1) % 3;
            for (auto e1 : adj[u]) {
                int u2 = e1.to;
                int c1 = (e1.c + t - 1) % 3 + 1;

                if (c1 != color[v]) continue;

                for (auto e2 : adj[v]) {
                    int v2 = e2.to;
                    int c2 = (e2.c + t - 1) % 3 + 1;

                    if (c2 != color[u]) continue;

                    if (!visited[u2][v2][nt]) {
                        visited[u2][v2][nt] = true;
                        q.push({u2, v2, nt, dist + 1});
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}