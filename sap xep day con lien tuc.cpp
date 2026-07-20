#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        int l, r;
        for (l = 0; l < n - 1; l++) {
            if (a[l] > a[l + 1])
                break;
        }
        for (r = n - 1; r > 0; r--) {
            if (a[r] < a[r - 1])
                break;
        }

        int mn = a[l], mx = a[l];

        for (int i = l; i <= r; i++) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        for (int i = 0; i < l; i++) {
            if (a[i] > mn) {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i > r; i--) {
            if (a[i] < mx) {
                r = i;
                break;
            }
        }

        cout << l + 1 << " " << r + 1 << '\n';
    }

    return 0;
}