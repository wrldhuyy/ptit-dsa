#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;

    while (T--) {

        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        set<int> uni;
        set<int> sa;
        for (int x : a) {
            uni.insert(x);
            sa.insert(x);
        }

        for (int x : b)
            uni.insert(x);
        for (int x : uni)
            cout << x << " ";

        cout << '\n';
        set<int> inter;

        for (int x : b) {
            if (sa.count(x))
                inter.insert(x);
        }

        for (int x : inter)
            cout << x << " ";

        cout << '\n';
    }

    return 0;
}