#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        bool digit[10] = {0};

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (char c : s) {
                digit[c - '0'] = true;
            }
        }

        for (int i = 0; i <= 9; i++) {
            if (digit[i]) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}