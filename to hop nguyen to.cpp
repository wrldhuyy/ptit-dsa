#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

bool prime(int x) {
    if (x < 2) return false;
    
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    
    return true;
}

void solve(int pos, int start) {
    if (pos == k) {
        int sum = 0;
        
        for (int x : a) sum += x;

        if (prime(sum)) {
            for (int x : a) cout << x << " ";
            cout << "\n";
        }
        return;
    }

    for (int i = start; i <= n - k + pos + 1; i++) {
        a.push_back(i);
        solve(pos + 1, i + 1);
        a.pop_back();
    }
}

int main() {
    cin >> n >> k;
    solve(0, 1);
    return 0;
}