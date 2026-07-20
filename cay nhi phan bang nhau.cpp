#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;

int left1[MAX], right1[MAX];
int left2[MAX], right2[MAX];

void init(int left[], int right[]) {
    for (int i = 0; i < MAX; i++) {
        left[i] = right[i] = -1;
    }
}

void build(int n, int left[], int right[]) {
    for (int i = 0; i < n; i++) {
        int u, v;
        char x;
        cin >> u >> v >> x;

        if (x == 'L') left[u] = v;
        else right[u] = v;
    }
}

bool isSame(int u, int v) {
    if (u == -1 && v == -1) return true;
    if (u == -1 || v == -1) return false;
    if (u != v) return false;

    return isSame(left1[u], left2[v]) &&
           isSame(right1[u], right2[v]);
}

int findRoot(int left[], int right[], int n) {
    set<int> child;
    for (int i = 1; i <= n; i++) {
        if (left[i] != -1) child.insert(left[i]);
        if (right[i] != -1) child.insert(right[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!child.count(i)) return i;
    }
    return -1;
}

int main() {
    int T; cin >> T;
    while (T--) {
        init(left1, right1);
        init(left2, right2);

        int n1; cin >> n1;
        build(n1, left1, right1);

        int n2; cin >> n2;
        build(n2, left2, right2);

        int root1 = findRoot(left1, right1, MAX);
        int root2 = findRoot(left2, right2, MAX);

        cout << (isSame(root1, root2) ? 1 : 0) << endl;
    }
}