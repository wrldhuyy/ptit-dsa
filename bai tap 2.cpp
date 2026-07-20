#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;
int n, s, t;
int c[105][105];
int dist[105], trace[105];
bool used[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        used[i] = false;
        trace[i] = -1;
    }
    dist[s] = 0;

    for (int k = 1; k <= n; k++) {
        int u = -1, minc = INF+1;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && dist[i] < minc) {
                minc = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        used[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!used[v] && c[u][v] < INF) {
                if (dist[v] > dist[u] + c[u][v]) {
                    dist[v] = dist[u] + c[u][v];
                    trace[v] = u;
                }
            }
        }
    }

    if (dist[t] >= INF) {
        cout << 0;
        return 0;
    }

    cout << dist[t] << "\n";
    vector<int> path;
    for (int v = t; v != -1; v = trace[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    for (int v : path) cout << v << " ";
    return 0;
}
