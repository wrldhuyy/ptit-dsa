#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 10000;
int n, s, c[105][105], d[105], parent[105];
bool visited[105];

void solve() {
if (!(cin >> n >> s)) return;
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= n; j++) {
cin >> c[i][j];
}
}

for (int i = 1; i <= n; i++) {
d[i] = INF;
visited[i] = false;
parent[i] = -1;
}

d[s] = 0;
int total_weight = 0;
vector<pair<int, int>> mst_edges;

for (int i = 1; i <= n; i++) {
int u = -1;

for (int j = 1; j <= n; j++) {
if (!visited[j] && (u == -1 || d[j] < d[u])) u = j;
}

if (u == -1 || d[u] == INF) break; 

visited[u] = true;
total_weight += d[u];

if (parent[u] != -1) {

mst_edges.push_back({u, parent[u]});
}

for (int v = 1; v <= n; v++) {
if (!visited[v] && c[u][v] > 0 && c[u][v] < INF) {
if (c[u][v] < d[v]) {
d[v] = c[u][v];
parent[v] = u;
}
}
}
}

if (mst_edges.size() != n - 1) {
cout << 0 << endl;
} else {
cout << total_weight << endl;

sort(mst_edges.begin(), mst_edges.end());

for (auto &e : mst_edges) {
cout << e.first << " " << e.second << endl;
}
}
}

int main() {

solve();
return 0;
}