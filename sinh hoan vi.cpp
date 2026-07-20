#include <bits/stdc++.h>
using namespace std;

int n;
bool used[11];
int a[11];

void backtrack(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = true;
            if (i == n) {
                for (int k = 1; k <= n; k++)
                    cout << a[k];
                cout << " ";
            } else {
                backtrack(i + 1);
            }
            used[j] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(used, false, sizeof(used));
        backtrack(1);
        cout << endl;
    }
}