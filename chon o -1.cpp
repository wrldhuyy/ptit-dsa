#include <bits/stdc++.h>
using namespace std;

long long a[21][21];
long long dp[1 << 20];

int main() {
 

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        int limit = 1 << n;
        for (int i = 0; i < limit; i++)
            dp[i] = -1;

        dp[0] = 0;

        for (int mask = 0; mask < limit; mask++) {
            int row = __builtin_popcount(mask);
            if (row >= n) continue;

            for (int col = 0; col < n; col++) {
                if (!(mask & (1 << col))) {
                    int newMask = mask | (1 << col);
                    dp[newMask] = max(dp[newMask],
                        dp[mask] + a[row][col]);
                }
            }
        }

        cout << dp[limit - 1] << "\n";
    }
}