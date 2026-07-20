#include <bits/stdc++.h>
using namespace std;

long long countPairs(int x, vector<int>& Y, int cnt[]) {
    int m = Y.size();

    if (x == 0) return 0;
    if (x == 1) return cnt[0];

    long long ans = m - (upper_bound(Y.begin(), Y.end(), x) - Y.begin());

    ans += cnt[0] + cnt[1];

    if (x == 2)
        ans -= (cnt[3] + cnt[4]);

    if (x == 3)
        ans += cnt[2];

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> X(n), Y(m);

        for (int &x : X) cin >> x;
        for (int &y : Y) cin >> y;

        sort(Y.begin(), Y.end());

        int cnt[5] = {0};
        for (int y : Y)
            if (y < 5) cnt[y]++;

        long long ans = 0;
        for (int x : X)
            ans += countPairs(x, Y, cnt);

        cout << ans << endl;
    }

    return 0;
}