#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int parent[MAXN];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a == b) return false; 

    parent[b] = a;
    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 1; i <= N; i++) parent[i] = i;

        bool hasCycle = false;

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;

            if (!union_set(u, v)) {
                hasCycle = true;
            }
        }

        cout << (hasCycle ? "YES\n" : "NO\n");
    }

    return 0;
}