#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> cnt(10000, 0);
        int x;

        for (int i = 0; i < n; i++) {
            cin >> x;
            cnt[x]++;
        }

        for (int i = 0; i < 10000; i++) {
            while (cnt[i]--) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}