#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {

        int n, X;
        cin >> n >> X;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        stable_sort(a.begin(), a.end(),
            [&](int u, int v) {

                return abs(X - u) < abs(X - v);

            });

        for (int x : a)
            cout << x << " ";

        cout << '\n';
    }

    return 0;
}