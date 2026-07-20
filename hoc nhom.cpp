#include <bits/stdc++.h>
using namespace std;

int parent[100005];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[v] = u;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }
    set<int> s;
    for (int i = 1; i <= N; i++) {
        s.insert(find(i));
    }

    cout << s.size();
}