#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

void solve(int pos, int start) {
    if (pos == k) {
        int tong = 0;

        for (int i = 1; i < k; i++) {
            tong += a[i] - a[i - 1];
        }

        if (tong > k) {
            for (int x : a) cout << x << " ";
            cout << "\n";
        }
        return;
    }

    for (int i = start; i <= n - k + pos + 1; i++) {
        a.push_back(i);
        solve(pos + 1, i + 1);
        a.pop_back();
    }
}

int main() {
    cin >> n >> k;
    solve(0, 1);
    return 0;
}