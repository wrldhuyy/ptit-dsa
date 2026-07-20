#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

long long C(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    long long res = 1;
    for (int i = 1; i <= k; i++)
        res = res * (n - i + 1) / i;
    return res;
}

long long rankComb(vector<int> &a) {
    long long rank = 1;
    int prev = 0;
    for (int i = 0; i < k; i++) {
        for (int j = prev + 1; j < a[i]; j++)
            rank += C(n - j, k - i - 1);
        prev = a[i];
    }
    return rank;
}

int main() {
    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; i++) a[i] = i + 1;

    while (1) {
        long long r = rankComb(a);
        if (isPrime(r)) {
            cout << r << ": ";
            for (int i = 0; i < k; i++)
                cout << a[i] << " ";
            cout << "\n";
        }

        int i = k - 1;
        while (i >= 0 && a[i] == n - k + i + 1) i--;
        if (i < 0) break;
        a[i]++;
        for (int j = i + 1; j < k; j++)
            a[j] = a[j - 1] + 1;
    }
}