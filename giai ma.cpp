#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();

        vector<long long> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = (s[0] != '0');

        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

            if (num >= 10 && num <= 26)
                dp[i] += dp[i - 2];
        }

        cout << dp[n] << '\n';
    }

    return 0;
}