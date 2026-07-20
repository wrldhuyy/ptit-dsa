#include <bits/stdc++.h>
using namespace std;

int n, K;
int a[20];
vector<int> ds;
int cnt = 0;

void backtrack(int i, int sum) {
    if (sum > K) return;

    if (i == n) {
        if (sum == K) {
            for (int x : ds) cout << x << " ";
            cout << "\n";
            cnt++;
        }
        return;
    }
    backtrack(i + 1, sum);
    ds.push_back(a[i]);
    backtrack(i + 1, sum + a[i]);
    ds.pop_back();
}

int main() {
    cin >> n >> K;
    for (int i = 0; i < n; i++) cin >> a[i];

    backtrack(0, 0);

    cout << cnt;
    return 0;
}
