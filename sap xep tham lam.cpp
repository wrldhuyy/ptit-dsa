#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> b = a;

        for (int i = 0; i < n / 2; i++) {
            int j = n - 1 - i;

            int mn = min(a[i], a[j]);
            int mx = max(a[i], a[j]);

            b[i] = mn;
            b[j] = mx;
        }

        if (is_sorted(b.begin(), b.end()))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}