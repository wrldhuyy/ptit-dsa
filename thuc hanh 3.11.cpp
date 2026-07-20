#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;
const int MAXN = 500005;

vector<pair<int,ll>> adj[MAXN];
ll d1[MAXN], d2[MAXN], d3[MAXN], d4[MAXN];

void dijkstra(int s, ll d[], int n) {
    for (int i = 1; i <= n; i++) d[i] = INF;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (du > d[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) adj[i].clear();

        int H1, S1, H2, S2;
        cin >> H1 >> S1 >> H2 >> S2;

        vector<tuple<int,int,ll>> edges;

        for (int i = 0; i < m; i++) {
            int u, v; ll w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            edges.push_back({u, v, w});
        }

        dijkstra(H1, d1, n);
        dijkstra(S1, d2, n);
        dijkstra(H2, d3, n);
        dijkstra(S2, d4, n);

        ll dist1 = d1[S1];
        ll dist2 = d3[S2];

        int ans = 0;
        bool infinite = false;
        for (int u = 1; u <= n; u++) {
            if (d1[u] + d2[u] == dist1 &&
                d3[u] + d4[u] == dist2 &&
                d1[u] == d3[u]) {
                ans++;
            }
        }
        for (auto [u, v, w] : edges) {
            if (d1[u] + w + d2[v] == dist1 &&
                d3[u] + w + d4[v] == dist2) {

                if ((d1[u] < d3[u] && d1[v] > d3[v]) ||
                    (d1[u] > d3[u] && d1[v] < d3[v])) {
                    infinite = true;
                }
            }
            if (d1[v] + w + d2[u] == dist1 &&
                d3[v] + w + d4[u] == dist2) {

                if ((d1[v] < d3[v] && d1[u] > d3[u]) ||
                    (d1[v] > d3[v] && d1[u] < d3[u])) {
                    infinite = true;
                }
            }
        }

        if (infinite) cout << "infinity\n";
        else cout << ans << '\n';
    }
}