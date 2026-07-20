#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1), pos(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int max_len = 1, cur = 1;

    for (int i = 2; i <= n; i++) {
        if (pos[i] > pos[i-1]) {
            cur++;
        } else {
            cur = 1;
        }
        max_len = max(max_len, cur);
    }

    cout << n - max_len;

    return 0;
}