#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    long long res = LLONG_MIN;
    res = max(res, a[n-1]*a[n-2]*a[n-3]);
    res = max(res, a[0]*a[1]*a[n-1]);
    res = max(res, a[n-1]*a[n-2]);
    res = max(res, a[0]*a[1]);

    cout << res;
}