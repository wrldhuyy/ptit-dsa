#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int &v : a) cin >> v;

        int l = lower_bound(a.begin(), a.end(), x) - a.begin();
        int r = upper_bound(a.begin(), a.end(), x) - a.begin();

        if (l == r) cout << -1;
        else cout << r - l;

        cout << endl;
    }

    return 0;
}