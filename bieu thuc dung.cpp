#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string s;
        getline(cin, s);

        int current = 0, maxDepth = 0;
        bool ok = true;

        for (char c : s) {
            if (c == '(') {
                current++;
                maxDepth = max(maxDepth, current);
            } 
            else if (c == ')') {
                current--;
                if (current < 0) {
                    ok = false;
                    break;
                }
            }
        }

        if (current != 0) ok = false;

        if (ok) cout << maxDepth << endl;
        else cout << -1 << endl;
    }

    return 0;
}