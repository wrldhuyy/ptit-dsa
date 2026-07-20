#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());

        int l = 0, r = n - 1;
        int ans = a[l] + a[r];

        while (l < r) {
            int sum = a[l] + a[r];

            if (abs(sum) < abs(ans))
                ans = sum;
            else if (abs(sum) == abs(ans))
                ans = min(ans, sum);

            if (sum < 0) l++;
            else r--;
        }

        cout << ans << endl;
    }

    return 0;
}