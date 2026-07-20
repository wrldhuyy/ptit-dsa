#include <bits/stdc++.h>
using namespace std;

void postorder(vector<int>& a, int l, int r) {
    if (l > r) return;

    int root = a[l];
    int m = l + 1;
    while (m <= r && a[m] < root) m++;
    postorder(a, l + 1, m - 1);
    postorder(a, m, r);
    cout << root << " ";
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        postorder(a, 0, n - 1);
        cout << endl;
    }
}