#include <bits/stdc++.h>
using namespace std;

int n;
int a[10];

void backtrack(int i) {
    if (i >= (n + 1) / 2) {
        for (int j = 0; j < n; j++) {
            cout << a[j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
        return;
    }

    for (int k = 0; k <= 1; k++) {
        a[i] = k;
        a[n - 1 - i] = k;
        backtrack(i + 1);
    }
}

int main() {
    cin >> n;
    backtrack(0);
    return 0;
}
