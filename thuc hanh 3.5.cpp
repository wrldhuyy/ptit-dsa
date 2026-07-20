#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int parent[MAXN], sz[MAXN];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]); 
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
     
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    for (int i = 1; i < MAXN; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    while (Q--) {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        if (Z == 1) {
            union_set(X, Y);
        } else {
            if (find_set(X) == find_set(Y)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}